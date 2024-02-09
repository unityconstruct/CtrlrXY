# dev-env-setup
###  WinGuide
https://godlike.com.au/fileadmin/godlike/techtools/ctrlr/guides/Compiling_Ctrlr_for_Windows_10_v2.1.pdf

### VS2022 - Required Workloads/Individual Components
- Note: VS2019 might be minimum version for THIS branch, THIS COMMIT & anything after
- Universal Windows Platform development
- Desktop development with C++
- VS 2019 Build Tools (v142) [if using VS2022, not needed if building on VS2019]

### Ctrlr Code
- on GitHub
  - https://github.com/damiensellier/CtrlrX/releases/tag/5.6.0
  - master: commit: 3f9819e
  - looks like this commit tagged 5.6.0
- Clone to `D:\source\repos\`
```bash
cd D:\source\repos\
git clone https://github.com/RomanKubiak/ctrlr
```
- Why not just create a new branch now? `master-init`
- unzip `D:\source\repos\ctrlr\Source\Misc\boost\boost.zip` -> `*\boost`

### JUCE 6.0.8
- Ctrlr 5.6.0 appears to use JUCE 6.0.8
  - https://github.com/juce-framework/JUCE/releases/tag/6.0.8
  - so in order for JUCE to correctly parse things, the versions MUST MATCH
  - V7 induced syntax errors in the 1000s, with missing semi colons, etc
- I don't like installing ANYTHING, so pulled the ZIP instead of installer
  - Extracted to `D:\Program Files\JUCE608`
- Start with `D:\Program Files\JUCE608\Projucer.exe`
- Globals
  - Prog Path: `D:\source\repos\ctrlr\JUCE`
  - Modules Path: `D:\source\repos\ctrlr\JUCE\modules`
- File>Open: `D:\source\repos\ctrlr\Ctrlr.jucer`
  - If JUCE throws an `Invalid JUCE Path` message... likely you are not using correct JUCE version
    - double-check the Globals Path
    - check JUCE version is `6.0.8` (as of this note - based off ctrlr:master:5.6.0:3f9819e)
  - A drop down list showing `Visual Studio 2019` should be shown
    - There's no EXPORT button or anything helpful like that
    - so click the VS icon & pray VS2022(or 2019) starts loading

# Visual Studio 2022
- All 4 projects build success and Project>Properties config is the same for each
- reminder: JUCE =>
  - `D:\source\repos\ctrlr\JUCE`
  - `D:\source\repos\ctrlr\JuceLibraryCode`
- reminder: lua => 
  - `D:\source\repos\ctrlr\Source\Misc\luabind\src`
  - `D:\source\repos\ctrlr\Source\Misc\lua\src`

- on first load, if VS version mismatch found, DO NOT update projects (requires Build Tools VS2019 (v142))
    - leave unchanged
- Init SLN Config
  - Build: Release | x64

### VS2022 PROJECTS
- INIT PROJ CONFIG:
  - Select project
  - `Project>Properties>Advanced>Preferred Build Tool Architecture`: 64-bit (x64)
  - `Project Properties>Configuration Properties>C/C++>OutputFiles`:
    - FROM: `$(IntDir)\`
    - TO: `<inherit from parent or project defaults>`
- Build


<hr/>

###  VS2022 PROJECT: Ctrlr_SharedCode
- INIT PROJ CONFIG: `Ctrlr_SharedCode`
  - at this point, only need to config `Ctrlr_SharedCode` - so select it
  - `Project>Properties>Advanced>Preferred Build Tool Architecture`: 64-bit (x64)
  - `Project Properties>Configuration Properties>C/C++>OutputFiles`:
    - FROM: `$(IntDir)\`
    - TO: `<inherit from parent or project defaults>`
- `Ctrlr_SharedCode`>Build

#### Build Notes
- generates: `D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\Shared Code\Ctrlr-x64.lib`
```output
1>Ctrlr_SharedCode.vcxproj -> D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\Shared Code\Ctrlr-x64.lib
1>Done building project "Ctrlr_SharedCode.vcxproj".
========== Build: 1 succeeded, 0 failed, 0 up-to-date, 0 skipped ==========
========== Build completed at 5:40 PM and took 03:32.808 minutes ==========
```

###  VS2022 PROJECT: Ctrlr_StandalonePlugin
- INIT PROJ CONFIG: `Ctrlr_StandalonePlugin`
  - at this point, only need to config `Ctrlr_StandalonePlugin` - so select it
  - `Project>Properties>Advanced>Preferred Build Tool Architecture`: 64-bit (x64)
  - `Project Properties>Configuration Properties>C/C++>OutputFiles`:
    - FROM: `$(IntDir)\`
    - TO: `<inherit from parent or project defaults>`
- `Ctrlr_StandalonePlugin`>Build

#### Build Notes
- JUCE lib: `include_juce_audio_plugin_client_Standalone.obj`
  - didn't see this in the build log, but didn't look hard either
- generates:  `D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\Standalone Plugin\Ctrlr-x64.exe`
- may or maynot have dependencies on `Ctrlr-x64.lib`, but based on size it seems the exe is truly `standalone`
- the build process may depend on the lib (rather than rebuild it blindly for each referencing project)
```output
1>Ctrlr_StandalonePlugin.vcxproj -> D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\Standalone Plugin\Ctrlr-x64.exe
1>Done building project "Ctrlr_StandalonePlugin.vcxproj".
========== Build: 1 succeeded, 0 failed, 1 up-to-date, 0 skipped ==========
========== Build completed at 5:51 PM and took 07:17.676 minutes ==========
```

###  VS2022 PROJECT:  Ctrlr_VST
- INIT PROJ CONFIG: `Ctrlr_VST`
  - at this point, only need to config `Ctrlr_VST` - so select it
  - `Project>Properties>Advanced>Preferred Build Tool Architecture`: 64-bit (x64)
  - `Project Properties>Configuration Properties>C/C++>OutputFiles`:
    - FROM: `$(IntDir)\`
    - TO: `<inherit from parent or project defaults>`
- `Ctrlr_VST`>Build

#### Build Notes
- JUCE lib: `include_juce_audio_plugin_client_VST2.cpp`
- generates: `D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST\Ctrlr-x64.dll`
```output
Started at 5:27 PM...
1>------ Build started: Project: Ctrlr_VST, Configuration: Release x64 ------
1>include_juce_audio_plugin_client_VST2.cpp
1>   Creating library D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST\Ctrlr-x64.lib and object D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST\Ctrlr-x64.exp
1>Generating code
1>D:\source\repos\ctrlr\Source\Core\CtrlrInlineUtilitiesGUI.h(87): warning C4715: 'gui::colourSchemeFromProperty': not all control paths return a value
1>D:\source\repos\ctrlr\Source\MIDI\CtrlrMidiInputComparatorSingle.cpp(239): warning C4702: unreachable code
1>Finished generating code
1>Ctrlr_VST.vcxproj -> D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST\Ctrlr-x64.dll
1>Done building project "Ctrlr_VST.vcxproj".
========== Build: 1 succeeded, 0 failed, 1 up-to-date, 0 skipped ==========
========== Build completed at 5:35 PM and took 07:40.480 minutes ==========
```

###  VS2022 PROJECT: Ctrlr_VST3
- INIT PROJ CONFIG: `Ctrlr_VST3`
  - at this point, only need to config `Ctrlr_VST3` - so select it
  - `Project>Properties>Advanced>Preferred Build Tool Architecture`: 64-bit (x64)
  - `Project Properties>Configuration Properties>C/C++>OutputFiles`:
    - FROM: `$(IntDir)\`
    - TO: `<inherit from parent or project defaults>`
- `Ctrlr_VST3`>Build
- 
#### Build Notes
- JUCE lib: `include_juce_audio_plugin_client_VST3.cpp`
- generates: `D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST3\Ctrlr-x64.vst3`

```output
Build started at 5:59 PM...
1>------ Build started: Project: Ctrlr_VST3, Configuration: Release x64 ------
1>include_juce_audio_plugin_client_VST3.cpp
1>   Creating library D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST3\Ctrlr-x64.lib and object D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST3\Ctrlr-x64.exp
1>Generating code
1>D:\source\repos\ctrlr\Source\Core\CtrlrInlineUtilitiesGUI.h(87): warning C4715: 'gui::colourSchemeFromProperty': not all control paths return a value
1>D:\source\repos\ctrlr\Source\MIDI\CtrlrMidiInputComparatorSingle.cpp(239): warning C4702: unreachable code
1>Finished generating code
1>Ctrlr_VST3.vcxproj -> D:\source\repos\ctrlr\Builds\VisualStudio2019\x64\Release\VST3\Ctrlr-x64.vst3
1>Done building project "Ctrlr_VST3.vcxproj".
========== Build: 1 succeeded, 0 failed, 1 up-to-date, 0 skipped ==========
========== Build completed at 6:07 PM and took 07:43.849 minutes ==========
```


## Build Notes - JUCE
- Inferred the JUCE version by `D:\source\repos\ctrlr\JUCE\ChangeList.txt`:
- README.md has `System Requirements` & `Support Targets`
```markdown
## Minimum System Requirements

#### Building JUCE Projects

- __macOS/iOS__: macOS 10.11 and Xcode 7.3.1
- __Windows__: Windows 8.1 and Visual Studio 2015 64-bit
- __Linux__: GCC 4.8 (for a full list of dependencies, see
[here](/docs/Linux%20Dependencies.md)).
- __Android__: Android Studio on Windows, macOS or Linux

#### Deployment Targets

- __macOS__: macOS 10.7
- __Windows__: Windows Vista
- __Linux__: Mainstream Linux distributions
- __iOS__: iOS 9.0
- __Android__: Jelly Bean (API 16)
```
- looks like JUCE libraries are pulled in by including cpp files that JUCE generates: `include_juce_audio_plugin_client_VST2.cpp`
- The initial JUCE Open>Export likely generates these for consumption by VS IDE
- 



#### 
- Ctrlr_SharedCode : [\Shared Code\Ctrlr-x64.lib]
  - Class Library used by other projects
- Ctrlr_StandalonePlugin
  - Core IDE
- Ctrlr_VST
  - Self-Explanatory, creates VST(2?) dll
- Ctrlr_VST3
  - Self-Explanatory, creates VST3 dll


# JUCE Comments

### JUCE - `JuceHeader.h`
- `D:\source\repos\ctrlr\JuceLibraryCode\JuceHeader.h`
- Saw mentions of VST3 issues with unique VST3 ID
- Possible this is where it needs to be changed
- Obviously changing source files requires.... REBUILD
  - might even require a re-export from JUCE, though not likely

```cpp
#if ! JUCE_DONT_DECLARE_PROJECTINFO
namespace ProjectInfo
{
    const char* const  projectName    = "Ctrlr";
    const char* const  companyName    = "Instigator";
    const char* const  versionString  = "5.5";
    const int          versionNumber  = 0x50500;
}
#endif
```


### JUCE - `JucePluginDefines.h`
 - `D:\source\repos\ctrlr\JuceLibraryCode\JucePluginDefines.h`
 - Guessing this holds GlobalVars and is code generated by the JUCE, so DO NOT CHANGE lest changes get overwritten
 - DataType seems to be autodetected, with string being in ""'s
 - 
```cpp
/*
  IMPORTANT! This file is auto-generated each time you save your
  project - if you alter its contents, your changes may be overwritten!
*/
#ifndef  JucePlugin_Vst3Category
 #define JucePlugin_Vst3Category           "Instrument|Synth"
#endif
```





#include <juce_audio_plugin_client/juce_audio_plugin_client_Standalone.cpp>
#include <juce_audio_plugin_client/juce_audio_plugin_client_VST2.cpp>
#include <juce_audio_plugin_client/juce_audio_plugin_client_VST3.cpp>