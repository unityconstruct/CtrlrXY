#include "stdafx.h"
#include "CtrlrManager/CtrlrManager.h"
#include "CtrlrPanel/CtrlrPanel.h"
#include "CtrlrLog.h"
#include "CtrlrEditor.h"
#include "CtrlrProcessor.h"
#include "CtrlrPanel/CtrlrPanelEditor.h"
#include "CtrlrPanel/CtrlrViewport.h"
#include "CtrlrPanel/CtrlrPanelViewport.h"
#include "CtrlrInlineUtilitiesGUI.h"

CtrlrEditor::CtrlrEditor (CtrlrProcessor *_ownerFilter, CtrlrManager &_owner)
	:	AudioProcessorEditor (_ownerFilter),
        ownerFilter(_ownerFilter),
		owner(_owner),
        resizer(this, 0),
		tempResult(Result::ok()),
		menuHandlerCalled(false),
		lastCommandInvocationMillis(0)
{
	LookAndFeel::setDefaultLookAndFeel(this);
	Rectangle<int> editorRect;
    // http://www.juce.com/forum/topic/applicationcommandmanager-menus-not-active-annoyance#new
    owner.getCommandManager().setFirstCommandTarget (this);

    menuBar = new MenuBarComponent (this);
    addAndMakeVisible(menuBar);
	// menuBarLookAndFeel = new CtrlrMenuBarLookAndFeel (*this);

	setApplicationCommandManagerToWatch (&owner.getCommandManager());

	owner.getCommandManager().registerAllCommandsForTarget (this);
	owner.getCommandManager().registerAllCommandsForTarget (JUCEApplication::getInstance());
	ScopedPointer <XmlElement> xml(XmlDocument::parse(owner.getProperty(Ids::ctrlrKeyboardMapping)).release());

	if (xml)
	{
		owner.getCommandManager().getKeyMappings()->restoreFromXml (*xml);
	}

	owner.setEditor (this);

	addAndMakeVisible (&owner.getCtrlrDocumentPanel());

	if (!JUCEApplication::isStandaloneApp()) // If Ctrlr is !NOT run as a standalone app but as a plugin or shared lib
    {
        if (owner.getInstanceMode() != InstanceSingleRestriced) // is !NOT restricted instance of the plugin
        {
            addAndMakeVisible(&resizer);
            resizer.setAlwaysOnTop(false);
            resizer.grabKeyboardFocus();
            resizer.toFront(true);
        }
    }
    
	if (owner.getProperty (Ids::ctrlrEditorBounds).toString() != "") // ctrlrEditorBounds is Editor size. AAX Plugin crashes here, passes without it
	{
        if (owner.getInstanceMode() != InstanceSingle && owner.getInstanceMode() != InstanceSingleRestriced)
		{
			editorRect = VAR2RECT(owner.getProperty(Ids::ctrlrEditorBounds)); // Size of full Editor window including top tabs and 2x1px borders
		}
		else if (owner.getActivePanel())
		{
            ValueTree editorTree = owner.getActivePanel()->getEditor()->getPanelEditorTree();  // owner is CtrlrManager for the current class
            editorRect = VAR2RECT(editorTree.getProperty(Ids::uiPanelCanvasRectangle));
            vpMenuBarVisible = editorTree.getProperty(Ids::uiPanelMenuBarVisible);
            vpResizable = editorTree.getProperty(Ids::uiViewPortResizable);
            vpEnableFixedAspectRatio = editorTree.getProperty(Ids::uiViewPortEnableFixedAspectRatio);
            vpFixedAspectRatio = editorTree.getProperty(Ids::uiViewPortFixedAspectRatio);

            vpEnableResizableLimits = editorTree.getProperty(Ids::uiViewPortEnableResizeLimits);
            vpMinWidth = editorTree.getProperty(Ids::uiViewPortMinWidth);
            vpMinHeight = editorTree.getProperty(Ids::uiViewPortMinHeight);
            vpMaxWidth = editorTree.getProperty(Ids::uiViewPortMaxWidth);
            vpMaxHeight = editorTree.getProperty(Ids::uiViewPortMaxHeight);
            
			if ((bool)owner.getActivePanel()->getEditor()->getProperty(Ids::uiPanelMenuBarVisible)) // Exp. instances get an override from uiPanelMenuBarHideOnExport
            {
                setMenuBarVisible(true); // Enable visibility
                editorRect.setHeight (editorRect.getHeight() + (int)owner.getProperty(Ids::ctrlrMenuBarHeight, 24));
			}
            else
            {
                editorRect.setWidth (editorRect.getWidth());
				editorRect.setHeight (editorRect.getHeight());
            }
            
            if (!JUCEApplication::isStandaloneApp() && owner.getInstanceMode() == InstanceSingleRestriced)
            {
                setResizable(vpResizable, true);
                CtrlrViewport().setScrollBarsShown(false,false);
 
                if (auto* constrainer = getConstrainer())
                {
                    if (vpEnableFixedAspectRatio == true)
                    {
                        constrainer->setFixedAspectRatio(vpFixedAspectRatio);

                        if (vpEnableResizableLimits == true)
                        {
                            if (vpMinWidth != 0 && vpMaxWidth != 0)
                            {
                                setResizeLimits(vpMinWidth, round(vpMinWidth/vpFixedAspectRatio), vpMaxWidth, round(vpMaxWidth/vpFixedAspectRatio));
                            }
                            else if (vpMinWidth != 0 && vpMinHeight != 0 && vpMaxWidth != 0 && vpMaxHeight != 0)
                            {
                                setResizeLimits(vpMinWidth, vpMinHeight, vpMaxWidth, vpMaxHeight);
                            }
                        }
                        else
                        {
                            constrainer->setMinimumSize(editorRect.getWidth(), editorRect.getHeight());
                        }
                    }
                    else if (vpEnableResizableLimits == true && vpMinWidth != 0 && vpMinHeight != 0 && vpMaxWidth != 0 && vpMaxHeight != 0)
                    {
                        setResizeLimits(vpMinWidth, vpMinHeight, vpMaxWidth, vpMaxHeight);
                    }
                }
            }
        }
		setBounds (editorRect);
	}
	else
	{
		if (JUCEApplication::isStandaloneApp())
			centreWithSize(800, 600);
		else
			setSize(800, 600);
	}

	setColourScheme(gui::colourSchemeFromProperty(owner.getProperty(Ids::ctrlrColourScheme)));

    getLookAndFeel().setUsingNativeAlertWindows((bool)owner.getProperty(Ids::ctrlrNativeAlerts));
	lookAndFeelChanged();
	activeCtrlrChanged();

	if (isRestricted() && owner.getActivePanel())
	{
		hideProgramsMenu = owner.getActivePanel()->getEditor()->getProperty(Ids::uiPanelProgramsMenuHideOnExport);
		hideMidiControllerMenu = owner.getActivePanel()->getEditor()->getProperty(Ids::uiPanelMidiControllerMenuHideOnExport);
		hideMidiThruMenu = owner.getActivePanel()->getEditor()->getProperty(Ids::uiPanelMidiThruMenuHideOnExport);
		hideMidiChannelMenu = owner.getActivePanel()->getEditor()->getProperty(Ids::uiPanelMidiChannelMenuHideOnExport);
	}
}

CtrlrEditor::~CtrlrEditor()
{
	deleteAndZero (menuBar);
	masterReference.clear();
}

void CtrlrEditor::paint (Graphics& g)
{
    g.fillAll(Colours::lightgrey);
}

void CtrlrEditor::resized()
{
	if (menuBar->isVisible())
	{
		menuBar->setBounds (0, 0, getWidth(), (int)owner.getProperty(Ids::ctrlrMenuBarHeight,24));
		owner.getCtrlrDocumentPanel().setBounds (0, (int)owner.getProperty(Ids::ctrlrMenuBarHeight,24), getWidth(), getHeight() - ((int)owner.getProperty(Ids::ctrlrMenuBarHeight,24)));
	}
	else
	{
		owner.getCtrlrDocumentPanel().setBounds (0, 0, getWidth(), getHeight()); // Needs offsets -1 , 0 +2, +1 for Cubase to disable auto scrollbars and hide borders
	}
	resizer.setBounds (getWidth()-24, getHeight()-24, 24, 24);
	owner.setProperty (Ids::ctrlrEditorBounds, getBounds().toString());
}


void CtrlrEditor::activeCtrlrChanged()
{
	ownerFilter->activePanelChanged();
	bool menuBarVisible = true;

	if (owner.getActivePanel() && owner.getActivePanel()->getEditor())
	{
		menuBarVisible = owner.getActivePanel()->getEditor()->getProperty(Ids::uiPanelMenuBarVisible);

		if (menuBarVisible != menuBar->isVisible())
		{
			setMenuBarVisible(menuBarVisible);
		}
	}
}

MenuBarComponent *CtrlrEditor::getMenuBar()
{
	return (menuBar);
}

CtrlrPanel *CtrlrEditor::getActivePanel()
{
	return (owner.getActivePanel());
}

bool CtrlrEditor::isRestricted()
{
	return (owner.getInstanceMode() == InstanceSingleRestriced);
}

CtrlrPanelEditor *CtrlrEditor::getActivePanelEditor()
{
	if (owner.getActivePanel())
	{
		return (owner.getActivePanel()->getEditor());
	}

	return (nullptr);
}

bool CtrlrEditor::isPanelActive(const bool checkRestrictedInstance)
{
	if (getActivePanel())
	{
		if (checkRestrictedInstance)
		{
			if (owner.getInstanceMode() == InstanceSingleRestriced)
			{
				return (false);
			}

			return (true);
		}
		else
		{
			return (true);
		}
	}

	return (false);
}

void CtrlrEditor::setMenuBarVisible(const bool shouldBeVisible)
{
	menuBar->setVisible (shouldBeVisible);
	resized();
}
