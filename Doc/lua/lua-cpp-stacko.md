# including lua in C projects

## project inclusion

- lua.c contains main and defines the entry point for a console application. If you remove it from the project, whats left builds into a standalone lib, or dynamic library if you prefer, just fine.
- Thanks for your answer! Just noticed that lua.c (stand-alone interpreter) and luac.c (Lua-to-Bytecode-Compiler) do contain a main - kinda weird that the source is not seperated into different folders…
- his organization is quite typical for classic Makefile based projects. Note the overall age of Lua. The Makefile does build (depending on the platform) both a static and dynamic library from the core, then compile lua.c and luac.c linked to them as appropriate
- aha, honestly, although I used MAKEFILES a bit, I never really grew fond of them and I always divided the applications into different folders…

<hr/>

- The following is what i use as a starting-point for my projects (I found something similar a while back and adapted it so I can change it faster):
- lua script
```lua
-- Start
-- Script: myscript.lua
print("this is lua")
-- End
```
- c file
```cpp
    #include <stdlib.h>
    #include <stdio.h>
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
    
    int main(char argv[], int argc) {
            static const luaL_Reg lualibs[] = {
                    { "base",       luaopen_base },
                    { NULL,         NULL }
            };
    
            static void openlualibs(lua_State *l) {
                    const luaL_Reg *lib;
    
                    for (lib = lualibs; lib->func != NULL; lib++) {
                            lib->func(l);
                            lua_settop(l, 0);
                    }
            }
    
            lua_State *l;
            l = lua_open();
            openlualibs(l);
    
            printf("now calling lua\n\n");
            lua_dofile(l, "myscript.lua");
            printf("\ndo something else\n\n");
    
            lua_close(l);
            return 0;
    }
```
<hr/>

- For a single-file amalgamation build of the Lua core and stand-alone interpreter, see the file etc/all.c in the official source kit. You can certainly use it as a basis for your own amalgamation, perhaps by eliminating the reference to lua.c on the last line.
- Many larger applications that embed Lua do it by simply adding the core source files to the project. This is particularly effective if the application intends to not permit extension code to load compiled modules from .dll or .so files. 
- If your application will permit compiled modules, then it is usually best to link against the shared library for the core so that the application and loaded modules can reference the symbols from a single instance of the core library. Note that accidental inclusion of multiple instances of the Lua core is almost guaranteed to produce very hard to diagnose symptoms.

