# ctrlr-org-doclinks
- Now the docs are not up to date, those that were are not apt since i did a major change. There is however a few ways to find out theese things.

Look at the bottom of:
- for panel methods: http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaPanel.cpp
- for modulator methods: http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaModulator.cpp
- for object methods (any modulator, panel, component is an object): http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaObject.cpp
- for timer methods: http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaMultiTimer.cpp
- for utility methods: http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaUtils.cpp
- panel editor,canvas,layer:
  - http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaPanelEditor.cpp
  - http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaPanelCanvas.cpp
  - http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/CtrlrLuaPanelCanvasLayer.cpp
- Also each object you define you can look at and list it’s methods: for example (you can do that in the Lua Console)
  - mod = panel:getModulatorByName("modulator1")
  - com = mod:getComponent()
  - what (mod) -- will print all the methods for the modulator
  - what (com) -- will print all the methods for the component
- To get a list of ALL classes bound to Lua, use the how() method
  - how()
- The documentation for classes that do not start with Ctrlr prefix is on the juce website: http://rawmaterialsoftware.com/juce/api/classes.html
- Always check if all methods are available. You can do that by looking at the class file in the http://sourceforge.net/p/ctrlrv4/code/1511/tree/nightly/Source/Lua/JuceClasses/ directory (each file .cpp/.h file pair represents one class and you can see what methods are bound to Lua and how).