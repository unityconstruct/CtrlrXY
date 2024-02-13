# CtrlrXY
 
 `CtrlrXY` is a fork of `CtrlrX` is a fork of `Ctrlr` originally by of `Roman Kubiak's Ctrlr`. 
 
 - `CtrlrX` is hosted by `Damien Sellier` & has taken the lead in pushing the project forward, notably with a recent `Look-and-Feel` update that significantly improved the overall UI & provides configurable UI properties for colors/fonts/ui components.
- `Ctrlr` repo can be found at https://github.com/RomanKubiak/ctrlr
- `Roman Kubiak` has created quite an amazing utility for musicians and prodect developers alike.

<hr/>

# Differentiation of this Fork
- This project was forked namely to allow it to be dissected & documented to produce much needed technical, architectural, use & setup documentation to enable newcomers get up to speed quickly & for legacy users/devs to more easily understand the code & get around.
- The results of THIS project being forked are actually being hosted in 3 other repos...
  - ...each of which are created in such a way to lend them to being `added as submodules & completely optional to building/using Ctrlr`.
  - `CtrlrDocs`
    - Amassing everything into this repo regardless of asset type, but items typically fall in one of these categories
        - source code documentation, diagrams, and code extraction to tables or more digestable/portable formats
        - lua code extracted from panels
        - lua language library that is holistic in nature for purposes of training on the language itself, creating generic utility methods, tutorials, Panel-extracted functions,
        - ctrlrlualib - lua code that is specific tailor
        - Ctrlr-specific notes, examples
        - language & tooling reference docus
  - `CtrlrLuaLib`
    - official library purposed for Ctrlr panels in a form that should be consumable/used by CtrlrXY-master, and/or any Ctrlr|CtrlrX repo/branch with compatible with both the Lua code, but also the foundational Ctrlr objects that are exposed. Typically if CtrlrXY can be merged/rebased onto/over the implementing project, CtrlrLuaLib should be fully usable.
  - `CtrlrPanels`
    - Amassing every panel encountered along with 'all things panel'
    - While the actual 'panel' files are the main asset, meta-files like images, decriptions, usage information will be collected

<hr/>

# Ctrlr Submodules

- must use the git submodule command to add submodules
- adding the specs to `.gitmodules` didn't trigger git properly & it never registered it internally, so was not polling the submodule(s) url to fetch the `<HEAD>commit`
- SYNTAX `git submodule add --name NAME URL PATH`
  - NAME is an arbitrary id that will show up in the project so it doesn't have to match the repo's name
  - URL is the repo's URL and can be in the form of `HTTP(https://github.com/)` or `SSH(git@github.com:)`
  - if using SSH the client must have keys registered for that repo/project/owner
- for CtrlrXY, gitmodules are using the SSH url & MUST be changed for end-users
  - VSCode prompted to authenticate between GitHub & VSCODE backend & that simply doesn't sound like a great idea,since ALL repos, the profile, and everything else would be essentially be accessible to those 3rd parties.
     - if VSCode has God-Mode on the GitHub account, then so do the VSCode Extensions & all of it just poses a security/hazard risk justifying requiring anyone using CtrlXY to run 3 `git submodule set-url NAME URL` commands

### add git submodule to project

```bash
## basic syntax
git submodule add git@github.com:path_to/submodule.git path-to-submodule
# public
git submodule add --name CtrlrDocs   https://github.com/unityconstruct/CtrlrDocs.git CtrlrDocs
git submodule add --name CtrlrLuaLib https://github.com/unityconstruct/CtrlrLuaLib.git CtrlrLuaLib
git submodule add --name CtrlrPanels https://github.com/unityconstruct/CtrlrPanels.git CtrlrPanels
# private
git submodule add --name CtrlrDocs   git@github.com:unityconstruct/CtrlrDocs.git CtrlrDocs
git submodule add --name CtrlrLuaLib git@github.com:unityconstruct/CtrlrLuaLib.git CtrlrLuaLib
git submodule add --name CtrlrPanels git@github.com:unityconstruct/CtrlrPanels.git CtrlrPanels
# update repo url to private
git submodule set-url CtrlrDocs   git@github.com:unityconstruct/CtrlrDocs.git
git submodule set-url CtrlrLuaLib git@github.com:unityconstruct/CtrlrLuaLib.git
git submodule set-url CtrlrPanels git@github.com:unityconstruct/CtrlrPanels.git

# update repo url to public
git submodule set-url CtrlrDocs   https://github.com/unityconstruct/CtrlrDocs.git
git submodule set-url CtrlrLuaLib https://github.com/unityconstruct/CtrlrLuaLib.git
git submodule set-url CtrlrPanels https://github.com/unityconstruct/CtrlrPanels.git
```

### .gitsubmodules result

```bash
[submodule "Panels"]
	path = Panels
	url = https://github.com/RomanKubiak/Panels.git
[submodule "CtrlrDocs"]
	path = CtrlrDocs
	url = git@github.com:unityconstruct/CtrlrDocs.git
[submodule "CtrlrLuaLib"]
	path = CtrlrLuaLib
	url = git@github.com:unityconstruct/CtrlrLuaLib.git
[submodule "CtrlrPanels"]
	path = CtrlrPanels
	url = git@github.com:unityconstruct/CtrlrPanels.git
```

### git/config result

- .git/config
```bash
[submodule "Panels"]
	active = true
	url = https://github.com/RomanKubiak/Panels.git

[submodule "CtrlrDocs"]
	url = git@github.com:unityconstruct/CtrlrDocs.git
	active = true
[submodule "CtrlrLuaLib"]
	url = git@github.com:unityconstruct/CtrlrLuaLib.git
	active = true
[submodule "CtrlrPanels"]
	url = git@github.com:unityconstruct/CtrlrPanels.git
	active = true
```

<hr/>

# README.md from CTRLX Repo Unchanged:

<hr/>

CtrlrX
=====

CtlrX is an alternative fork of Roman Kubiak's Ctrlr.
This project is ONLY aimed at delivering updates, a wiki, documentation, tutorials or anything that the community cannot share on the original Ctrlr github due to credential restrictions. 
Let's keep the Ctrlr github alive and keep up with what we were all doing there. But for anything that deserves special credentials unavailable there, just let's do it here on CtrlrX.


ToDo
----

* VST Host must get the panel name while exported as VST3 plugin (currently always named as Ctrlr | Instigator)
* APP/Plugin identifiers properly updated from panel infos in exported instances package.(info.plist, .exe, vst3, etc)
* Implementation of the entire JUCE ValueTree Class with LUA
* File path needs to be updated on save while the panel ID is changed (Save vs. Save as...)
* Modulators located within a tabs must have their properties updated while the tab properties are changed 
* Allow earlier "Undo" after a modulator has been deleted
* Export instance process must be improved (dialog alerts, overwriting existing file...)
* VST Parameter Index must start at 0 not 1 in Hosts (now VST Index 0 in Ctrlr is Param 1 in Cubase)
* Re-generating UID must update resource path automatically
* Update to the latest version of JUCE 7


Changelog
---------

#### Version 5.6.29

* Implementation of the entire JUCE LookAndFeel_V4 design with all color schemes
* Panels designed on previous versions (5.3.198 & 5.3.220) are compatible and will automatically use LookAndFeel_V2/V3
* Implementation of the JUCE ColourSelector popup for every coloUr properties
* Description/ID in the property pane switches without selecting other tabs to update
* Overall improvement of Ctrlr GUI, component settings and functionalities

#### Version 5.6.28
*  Added support for scalable UI for responsive design via callback on APP/Plugin viewport resize and viewport resize parameters.
*  Fixed menuBar not showing up issue for non-restricted exported instance.

#### Version 5.6.27
*  uiPanelViewPortBackgroundColour property added in the global properties to change the background color of the ViewPort, parent of the Panel canvas.

#### Version 5.6.26
*  setChangeNotificationOnlyOnRelease added in the component section for all types of sliders. When enabled, it sends the Value only when the mouse button is released.

#### Version 5.6.25
* mouseUp, mouseEnter, mouseExit callbacks added in for Generic Components (buttons, sliders etc)

#### Version 5.6.24
* ctrlrEditor window showing scrollbars over canvas in Cubase has been fixed

#### Version 0.0.0
* Current version is forked from Ctrlr 5.6.23
* Requires unified versioning pattern



# About Ctrlr

Control any MIDI enabled hardware: synthesizers, drum machines, samplers, effects. Create custom User Interfaces. Host them as VST or AU plugins in your favorite DAWs.


Cross Platform
--------------
Works on Windows (XP and up, both 64 and 32bit binaries are available), macOS (10.5 and up), Linux (any modern distro should run it).
Host in your DAW

Each platform has a VST build of Ctrlr so you can host your panels as normal VST plugins, for macOS a special AU build is available.

Customize
---------
Each Panel can be customized by the user, the panels are XML files, every panel can be Edited in Ctrlr to suite your specific needs.

Open Source
-----------
Need special functionality or want to propose a patch/feature update, know a bit about C++/JUCE framework etc. You can always download the source code and build Ctrlr by yourself.

Extend
------
With the scripting possibilities inside Ctrlr you can extend you panels in various ways. The LUA scripting language gives you access to all panels elements and hooks to various events.


# How to build Ctrlr


## Windows

Summary will be added here in the future, links to pdf of build guides by @bijlevel can be found here

[Compiling on Windows 10](https://godlike.com.au/fileadmin/godlike/techtools/ctrlr/guides/Compiling_Ctrlr_for_Windows_10_v2.1.pdf)


## macOS

[Compiling on OSX](https://godlike.com.au/fileadmin/godlike/techtools/ctrlr/guides/My_guide_to_compiling_Ctrlr_for_macOS__Mojave__v2.pdf)


## Linux

A build.sh script is provided in Builds/Generated/Linux/Standalone, a symlink of that
script is location in Builds/Generated/Linux/VST and is used to create a precompiled header
and then to trigger the build using make. You can do that manualy if you like just have
a look at the script, it's really simple.

A more complex solution exists in Scripts/post-commit, this script will build all solutions
for the current architecture, it will also prepare the system for the build, unpack boost.zip
check some packages (on Ubuntu only for now) and start the build. At the end it will create
a self extracting Ctrlr.sh file in Packaging/Linux (create using makeself.sh), it will also
try to scp it to ctrlr.org but that will fail without the correct ssh key, you can just comment
out the scp line in post-commit.

The post-commit script takes an argument "clean" if you wish to clean all the intermididate
files before building. If you want to ignore any package errors that it reports (i assume you
know your system better then my script) then just add -f as an option when building.

# How to export plugin instances (AU, AUv3, VST & VST3)

## VST2 Support
Since Steinberg has discontinued the VST2 API we no longer distribute a VST2. If you are a licensee to the VST2SDK, though, you can still build it. 
The first thing is to be sure to check the path to the VST2 sdk (only available from Steinberg's VST3 directory sdk) in Projucer before calling any script builds.

## VST3 Support
Currently VST3 instances of CTRLR panels are not working properly because CTRLR is not able to generate different VST3 compliant plugin identifiers. 
Unfortunately, exported VST3 instances of your panel will always be named after CTRLR | Instigator. 
The only way to get the correct identifiers for a panel project is to force them at the core during the building step of the VST3 in Xcode/VS/IDE.
To export properly identified VST3 plugins it is then required to build a different stock CTRLR VST3 plugin with JUCE Projucer and Xcode/VS/IDE. 
However, this alternative version of CTRLR VST3 will have the desired panel/plugin identifiers predefined in the Projucer settings. (Plugin Name, Manufacturer Name, Plugin ID, Manufacturer ID etc). 
This intermediate VST3 plugin will then be able to export a final VST3 version of the panel with the proper identifiers. 

## AU Support
Tutorial coming soon

## AUv3 Support
Tutorial coming soon

# Credits
* Thanks to @romankubiak for developing Ctrlr
* Links to contributors coming soon

# Notes
* VST is a registered trademark of Steinberg Media Technologies GmbH
