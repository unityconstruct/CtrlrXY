#include "stdafx.h"
#include "CtrlrManager/CtrlrManager.h"
#include "CtrlrEditor.h"
#include "CtrlrMacros.h"
#include "CtrlrProcessor.h"
#include "CtrlrPanel/CtrlrPanelEditor.h"
#include "CtrlrDocumentPanel.h"
#include "CtrlrInlineUtilitiesGUI.h"

CtrlrDocumentPanel::CtrlrDocumentPanel (CtrlrManager &_owner)
    : ctrlrEditor(0), owner(_owner)
{
	/* Full screen mode is not completely implemented in JUCE 6
	   we get some assertions when adding the first Tab to an invisble
	   panel, as it wants to grep the focus, which is not possible at this stage.
	*/
	// useFullscreenWhenOneDocument (true);
    setSize (600, 400);
    //setBackgroundColour(Component::findColour(DocumentWindow::backgroundColourId)); // Cannot catch the active window LnF
    setBackgroundColour(Colours::lightgrey); // Sets background colour behind main window
}

CtrlrDocumentPanel::~CtrlrDocumentPanel()
{
}

void CtrlrDocumentPanel::resized()
{
	MultiDocumentPanel::resized();
}

bool CtrlrDocumentPanel::tryToCloseDocument (Component* component)
{
	return (true);
}

void CtrlrDocumentPanel::activeDocumentChanged()
{
	CtrlrEditor *ed = dynamic_cast <CtrlrEditor*> (getParentComponent());
	if (ed)
    {
		ed->activeCtrlrChanged();
        setBackgroundColour(Component::findColour(DocumentWindow::backgroundColourId));
    }
    if (getCurrentTabbedComponent()) {
        getCurrentTabbedComponent()->setTabBarDepth(owner.getProperty(Ids::ctrlrTabBarDepth));
        getCurrentTabbedComponent()->getTabbedButtonBar().setColour(TabbedButtonBar::tabTextColourId, findColour(TabbedButtonBar::tabTextColourId)); // Not working
        getCurrentTabbedComponent()->getTabbedButtonBar().setColour(TabbedButtonBar::frontTextColourId, findColour(TabbedButtonBar::frontTextColourId)); // Not working
    }
    setBackgroundColour(Colours::lightgrey); // Sets background colour behind main window by default on grey to please everyone :)
}

void CtrlrDocumentPanel::setEditor (CtrlrEditor *_editorToSet)
{
	ctrlrEditor = _editorToSet;
}

void CtrlrDocumentPanel::lookAndFeelChanged()
{
    setBackgroundColour(Component::findColour(DocumentWindow::backgroundColourId));
}
