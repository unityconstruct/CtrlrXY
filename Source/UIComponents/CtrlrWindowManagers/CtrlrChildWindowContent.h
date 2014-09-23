#ifndef __CTRLR_CHILD_WINDOW_CONTENT__
#define __CTRLR_CHILD_WINDOW_CONTENT__

#include "CtrlrMacros.h"

class CtrlrChildWindowContainer;

class CtrlrChildWindowContent :	public Component
{
	public:
		CtrlrChildWindowContent();
		virtual ~CtrlrChildWindowContent();
		void setContainer(CtrlrChildWindowContainer *_container);
		virtual String getContentName();
		virtual ValueTree &saveState();
		ValueTree &getComponentTree() { return (componentTree); }
		virtual void restoreState (const ValueTree &) {}
		virtual uint8 getType()=0;

		virtual StringArray getMenuBarNames() { return (StringArray()); }
		virtual PopupMenu getMenuForIndex(int, const String &) { return (PopupMenu()); }
		virtual void menuItemSelected(int, int ) {}
		virtual bool keyPressed (const KeyPress &, Component *) { return (false); }
		JUCE_LEAK_DETECTOR(CtrlrChildWindowContent)

	protected:
		ValueTree componentTree;
		CtrlrChildWindowContainer *container;
};
#endif
