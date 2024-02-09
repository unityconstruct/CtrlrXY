# ctrlr-versions-workflows

- Successfully built `ctrlr-5.6.0:master` & `CtrlrX-latest:master`

### Version links?
- Ran into what I think is a known 'MIDI not implemented' situation with the tip revisions.
  - for Standalone that is
- Parsing the board in pursuit of 'due diligence', found 3/4 releases commonly mentioned.
- The more I look at it the more I'm getting turned around on where to pull code from for the various releases
  - though I think I understand 2 versions _(that are mentioned less for the various workflows)_
- **Anyone have links to these versions?**

### Version usage
- saw some conversations about working around the version limitations, based on needed target
- My takeways
  - VST3: PANEL DEV: `6.0.26` _(to pick up JUCE or other enhancements + stability.. BUT, no MIDI(?))_
    - requires project rebuild to pick up VST3 instrument names, etc
  - VST3: PANEL EXPORT: `5.6.23`
  - VST2: PANEL DEV: `5.3.201`
  - VST2: PANEL EXPORT: `5.3.201`
  - AU: PANEL DEV: `5.3.201`
  - AU: PANEL EXPORT: `5.3.201`
  - STANDALONE: PANEL DEV: `5.3.201`
  - STANDALONE: PANEL EXPORT: `5.3.201`
  - CTRLR DEV: `??????`


| Feature | Operation | mac | pc | Comment |
| -- | -- | -- | -- | -- |
| VST3 | PANEL DEV | `5.6.23+`  | `5.6.23+`  | VST3, JUCE-6.0.8, Lua-5.1.4  |
| VST3 | PANEL EXPORT | `5.6.23+`  | `5.6.23+` | VST3 builds require at least the Ctrlr version moddified by @jmechnich to work properly with xcode. <br/>
https://github.com/jmechnich/ctrlr/releases/tag/5.6-f452347 |
| VST2 | PANEL DEV | PC: `5.3.201` | MAC: `5.3.198` |  |
| VST2 | PANEL EXPORT | PC: `5.3.201` | MAC: `5.3.198` |  |
| AU | PANEL DEV | PC: `5.3.201` | MAC: `5.3.198` |  |
| AU | PANEL EXPORT | PC: `5.3.201` | MAC: `5.3.198` |  |
| STANDALONE | PANEL EXPORT | PC: `5.3.201` | MAC: `5.3.198` |  |
| STANDALONE | PANEL EXPORT | PC: `5.3.201` | MAC: `5.3.198` |  |
| CTRLR | DEV | `CtrlrX-5.6.28` | `CtrlrX-5.6.28` |  |
|  | PANEL |  |  |  |


### Old-Old Official Builds_(ctrlr.org)_
- https://ctrlr.org/nightly/?C=M;O=D
### New-Old Official Releases _(github)_
- https://github.com/RomanKubiak/ctrlr/releases

<hr/>

### Current Tip Revisions [as of 2024-01-29] :
- ctrlr - `5.6.0`= `5.6.23`
- CtrlrX - `5.6.28` _(forked from `5.6.23`)_ _( master merge a few days ago )_

### Ctrlr Versions
- `6.0.26` - _(likely only available as executable binaries)_
- `5.6.28` _(CtrlrX - assuming this version as its the last mentioned in the README)_
  - [master branch](https://github.com/damiensellier/CtrlrX)
- `5.6.23` _(= `5.6.0`)_
  - [master branch](https://github.com/RomanKubiak/ctrlr)
- `5.6.0`  _(ctrlr - 5.6.0 tag is on commit, not a release)_
- `5.6.1` _(DMG ONLY release for mac)_
  - [5.6.0 Release Page](https://github.com/RomanKubiak/ctrlr/releases/tag/5.6.0)
  - [Ctrlr-5.6.1.dmg](https://github.com/RomanKubiak/ctrlr/releases/download/5.6.0/Ctrlr-5.6.1.dmg)
- `5.3.201` _(likely only available as executable binaries)_


| Repo | Version | Lua | JUCE | Features | Comment |
| -- | -- | -- | -- | -- | -- |
| Ctrlr | `5.3.198` | ???? | ????? | VST2.4,STANDALONE | for MAC |
| Ctrlr | `5.3.201` | ????,| ????? | VST2.4,STANDALONE | for PC |
| Ctrlr | `5.6.0` | `5.1.4` | `6.0.8` |  |  |
| Ctrlr | `5.6.0` | `5.1.4` | `6.0.8` |  |  |
| Ctrlr | `5.6.23` | `5.1.4` | `6.0.8` |  |  |
| CtrlrX | `5.6.28` | `5.1.4` | `6.0.8` |  |  |
| Ctrlr | `6.0.26` | `5.1.4` | `6.0.8` |  |  |





# CTRLR 5.6.0: Lua 5.14: References
- [Lua 5.0] 
  - [The official Lua site](https://www.lua.org/start.html)
  - [The official Lua 5.0 HTML manual: Programming in Lua](https://www.lua.org/manual/5.0/)
  - [The 'official' Lua 5.0 PDF version: Programming in Lua 2ndEd.](https://archive.org/details/programminginlua0000ieru)
- [Lua 5.1.1] 
  - [Wiley Beginning Lua Programming](https://archive.org/details/manualzilla-id-7144032/mode/2up)
- [Lua 5.3] 
  - [The 'official' Lua 5.0 PDF version: Programming in Lua 4thEd.](https://archive.org/details/pil-4th)

<hr/>

### Comments

## `5.6.23` - VST3
- If you want VST3, the only option is `5.6.23`, and you will need to recompile it to bake in the plugin name and manufacturer. The binaries are available here - https://godlike.com.au/index.php?id=361
- Develop in stable version, compile VST3 in this version

### benefits
#### What are the benefits of `5.6.23`?
- I only use `5.3.201`. There are documented workarounds for `5.3.201` so it’s very stable for my needs.
  - That's my question, my experience is that under v`5.3.201` all the scripts on "luaModulatorValueChange" get triggered on panel startup but with v`5.6.23` they do not ???
- Scripts don’t get triggered on startup using my code in the other post in `5.3.201` for me at least.
  - … Timer Script "unBlock" does NOT get triggered when your Panel is loaded into v`5.6.23`
- To trigger the unblock function in `5.6.23` maybe take it out of the hidden uiButton and set the timer in an init() script and make the delay 1000ms or something big?
#### I'm using `5.6.23` only to generate VST3 Restricted Instances, which I have now got to work, but that's a whole different topic!
- In the end I have a `5.6.23` specific panel where I just do something very similar to running the Timer from the init() script like you say, and that seems to work fine.
- It just seems a fundamental difference in the way the 2 versions work and wondered if anyone else had noticed?
#### testing it
- I just tried creating a simple panel with a function that sets a uiSlider to value 127. The function doesn't seem to trigger at all when I load the panel like it would in `5.3.201`
  - Exactly, fundamentally different behaviour on Panel Load!


## `6.0.26` - Stable for development
- If you are building VST3 with this, I recommend developing with `6.0.26` which is more stable. `5.6.23` will crash without showing why, unless you manually invoke functions in protected space using Assert. Once code is working, test it in `5.6.23` and then render out your VST3's

## `5.3.201`/5.3.198 - stable releases
- If you just want AU, standalone and VST2, then `5.3.201`/5.3.198 is the way to go.

## `5.6.23` and `6.0.26` - \n
- The main differences are that `5.6.23` and `6.0.26` require an extra option "\n" at the end of writeFileAsText and they won't allow tables to be used as inputs to make MIDI messages. You need to cast them as memoryBlocks first (or convert to strings)



### Old Official Builds: https://ctrlr.org/nightly/?C=M;O=D
[Ctrlr-5.3.191.exe](https://ctrlr.org/nightly/Ctrlr-5.3.191.exe)                                  07-Apr-2017 11:31            12418210
[Ctrlr-5.3.193.exe](https://ctrlr.org/nightly/Ctrlr-5.3.193.exe)                                  07-Apr-2017 11:31            12415654
[Ctrlr-5.3.196.exe](https://ctrlr.org/nightly/Ctrlr-5.3.196.exe)                                  07-Apr-2017 11:31            12417540
> _**[Ctrlr-5.3.198.dmg](https://ctrlr.org/nightly/Ctrlr-5.3.198.dmg)                                  07-Apr-2017 11:33            45063483**_

[Ctrlr-5.3.199.exe](https://ctrlr.org/nightly/Ctrlr-5.3.199.exe)                                  07-Apr-2017 11:34            12446672

> _**[Ctrlr-5.3.201.exe](https://ctrlr.org/nightly/Ctrlr-5.3.201.exe)                                  07-Apr-2017 11:35            12452001**_
- in the ballpark with 5.3.201 in codebase, but will be tricky if 5.3 was updated after these builds
- assuming 5.3.201 is build 201 - meaning that 201 builds done on a particular commit..
  - highly doubtful 201 will be found anywhere in repo, so inference is really only way
  - given multiple builds can occur in a day OR no builds can occur in a day.. mostly a commt-by-commit check
  - there may be NO benefit to anything beyond the binaries, so pausing search ATM
- FILEVERSION  5,3,0,0
- [9a2ce62](https://github.com/RomanKubiak/ctrlr/commit/9a2ce62201bcc03033edb6f03b00930405897265)
- 6 years ago 6/18/2018

[Ctrlr-5.4.11.exe](https://ctrlr.org/nightly/Ctrlr-5.4.11.exe)                                   07-Apr-2017 11:37            12950017
[Ctrlr-5.4.16.exe](https://ctrlr.org/nightly/Ctrlr-5.4.16.exe)                                   07-Apr-2017 11:38            14225589
[Ctrlr-5.4.2.exe](https://ctrlr.org/nightly/Ctrlr-5.4.2.exe)                                    07-Apr-2017 11:35            12949582
[Ctrlr-5.4.24.exe](https://ctrlr.org/nightly/Ctrlr-5.4.24.exe)                                   07-Apr-2017 11:39            14857617
[Ctrlr-5.4.27.exe](https://ctrlr.org/nightly/Ctrlr-5.4.27.exe)                                   07-Apr-2017 11:40            14953142
[Ctrlr-5.4.29.exe](https://ctrlr.org/nightly/Ctrlr-5.4.29.exe)                                   07-Apr-2017 11:40            14869130
[Ctrlr-5.5.2.exe](https://ctrlr.org/nightly/Ctrlr-5.5.2.exe)                                    08-May-2017 15:45            18490878
[Ctrlr-6.0.1.exe](https://ctrlr.org/nightly/Ctrlr-6.0.1.exe)                                    09-Jan-2019 20:03            25789966
[Ctrlr-6.0.1.win32.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.1.win32.build.log)                        09-Jan-2019 20:03                   0
[Ctrlr-6.0.1.win64.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.1.win64.build.log)                        09-Jan-2019 20:03                   0
[Ctrlr-6.0.25.exe](https://ctrlr.org/nightly/Ctrlr-6.0.25.exe)                                   03-Oct-2019 12:45            25738846
[Ctrlr-6.0.25.win32.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.25.win32.build.log)                       03-Oct-2019 12:45                   0
[Ctrlr-6.0.25.win64.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.25.win64.build.log)                       03-Oct-2019 12:45                   0

> _**[Ctrlr-6.0.26.exe](https://ctrlr.org/nightly/Ctrlr-6.0.26.exe)                                   07-Oct-2019 14:54            31118337**_
> _**[Ctrlr-6.0.26.win32.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.26.win32.build.log)                       07-Oct-2019 14:54                   0**_
> _**[Ctrlr-6.0.26.win64.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.26.win64.build.log)                       07-Oct-2019 14:54                   0**_

[Ctrlr-6.0.4.exe](https://ctrlr.org/nightly/Ctrlr-6.0.4.exe)                                    16-Jan-2019 17:33            26294401
[Ctrlr-6.0.4.win32.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.4.win32.build.log)                        16-Jan-2019 17:33                   0
[Ctrlr-6.0.4.win64.build.log](https://ctrlr.org/nightly/Ctrlr-6.0.4.win64.build.log)                        16-Jan-2019 17:33                   0
[Ctrlr-i686-5.3.189.sh](https://ctrlr.org/nightly/Ctrlr-i686-5.3.189.sh)                              07-Apr-2017 11:30            13998261
[Ctrlr-i686-5.3.191.sh](https://ctrlr.org/nightly/Ctrlr-i686-5.3.191.sh)                              07-Apr-2017 11:30            13988857
[Ctrlr-i686-5.3.199.sh](https://ctrlr.org/nightly/Ctrlr-i686-5.3.199.sh)                              07-Apr-2017 11:34            14013029
[Ctrlr-i686-5.4.16.sh](https://ctrlr.org/nightly/Ctrlr-i686-5.4.16.sh)                               07-Apr-2017 11:39            14232884
[Ctrlr-x86_64-5.3.188.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.3.188.sh)                            07-Apr-2017 11:29            18170479
[Ctrlr-x86_64-5.3.192.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.3.192.sh)                            07-Apr-2017 11:30            18123438
[Ctrlr-x86_64-5.3.196.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.3.196.sh)                            07-Apr-2017 11:32            18129802
[Ctrlr-x86_64-5.3.199.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.3.199.sh)                            07-Apr-2017 11:34            18208405

> _**[Ctrlr-x86_64-5.3.201.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.3.201.sh)                            07-Apr-2017 11:35            18213576**_

[Ctrlr-x86_64-5.4.11.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.4.11.sh)                             07-Apr-2017 11:36            16680052
[Ctrlr-x86_64-5.4.14.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.4.14.sh)                             07-Apr-2017 11:37            16615885
[Ctrlr-x86_64-5.4.16.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-5.4.16.sh)                             07-Apr-2017 11:38            16617332
[Ctrlr-x86_64-6.0.0.linux.build.log](https://ctrlr.org/nightly/Ctrlr-x86_64-6.0.0.linux.build.log)                 10-Jan-2019 16:22                 314
[Ctrlr-x86_64-6.0.0.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-6.0.0.sh)                              10-Jan-2019 16:22            16504841
[Ctrlr-x86_64-6.0.1.linux.build.log](https://ctrlr.org/nightly/Ctrlr-x86_64-6.0.1.linux.build.log)                 10-Jan-2019 16:25                 314
[Ctrlr-x86_64-6.0.1.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-6.0.1.sh)                              10-Jan-2019 16:25            16503899
[Ctrlr-x86_64-6.0.35.linux.build.log](https://ctrlr.org/nightly/Ctrlr-x86_64-6.0.35.linux.build.log)                11-May-2020 18:27                 501
[Ctrlr-x86_64-6.0.35.sh](https://ctrlr.org/nightly/Ctrlr-x86_64-6.0.35.sh)



# Lua Versions/Funcs in CTRLR 

There are differences in bit operations depending on the Lua version.

The following bitwise operations are possible in Lua 5.1:
─ bit.tohex (x[,n]) -- convert x to hex with n digits (default 8)
─ bit.bnot (x) -- bitwise not of x
─ bit.band (x1[,x2...]) -- bitwise and of x1, x2, ...
─ bit.bor (x1[,x2...]) -- bitwise or of x1, x2, ...
─ bit.bxor (x1[,x2...]) -- bitwise xor of x1, x2, ...
─ bit.lshift (x, n) -- left-shift of x by n bits
─ bit.rshift (x, n) -- logical right-shift of x by n bits
─ bit.arshift (x, n) -- arithmetic right-shift of x by n bits
─ bit.rol (x, n) -- left-rotate of x by n bits
─ bit.ror (x, n) -- right-rotate of x by n bits
─ bit.bswap (x) -- byte-swap of x (little-endian <-> big-endian)

With Lua 5.3, it will be possible to use the built-in operators:
─ &: bitwise and
─ |: bitwise or
─ ~: bitwise exclusive or
─ >>: right shift
─ <<: left shift
─ ~: unary bitwise not

In Ctrlr 6.0.26, it is maybe Lua 5.3...
In Ctrlr 5.3.201 that I'm using it is Lua 5.1

<hr/>

- 6.0.26 uses Lua 5.1.4. The binary functions don't have shorthand like >> or << or ||, but it's really not a hassle.

<hr/>

- In some of my panels I use my own LUA function to replace bit.and and the likes, because I wanted it to work on many different Ctrlr and LUA versions, including older ones.
```lua
function bitband(a, b)
    local result = 0
    local bitval = 1
    while a > 0 and b > 0 do
      if a % 2 == 1 and b % 2 == 1 then -- test the rightmost bits
          result = result + bitval      -- set the current bit
      end
      bitval = bitval * 2 -- shift left
      a = math.floor(a/2) -- shift right
      b = math.floor(b/2)
    end
    return result
end
```

