# Integrating Lua into C++
RichardS
```
2 Sep 2005
CPOL
8 min read
 330.2K    8.6K    127    40
An article about embedding the Lua scripting language with C++ objects.
```
- [Download source files - 127 Kb](https://www.codeproject.com/KB/cpp/luaincpp/luaincpp_src.zip)
- [Download demo project - 94.3 Kb](https://www.codeproject.com/KB/cpp/luaincpp/luaincpp_demo.zip)

# Introduction
- Ever wanted to tweak a value or two without having to compile the whole code section over again? Then maybe an embedded script is your answer. This is where Lua comes in handy. Lua is an embeddable script interpreter that is lightweight and fast. You can learn more on the Lua site.

# Background
- Often I have come up against the situation in programming when the need arises to tweak and twiddle in order to arrange items or to set their values. This always requires rebuilding (or edit/continuing) the code over and over again, which wastes a lot of time and hence the idea of incorporating a scripting language in the program. This way I could just change the script, save it and re-run the program over and over again saving a lot of building time.

## So why Lua?
- Lua is a powerful light-weight, small footprint programming language designed for extending applications. Along with this Lua provides its own memory management through garbage collection (which can be specialized for your application). Lua is also fully re-entrant code with no global variables.

## Why not use LuaBind?
- For those out there who do not know about this, check out LuaBind. LuaBind is great product but for me it looked too complicated. For one the code is not easy to follow where the classes and objects are. Also seeing that I wanted to integrate Lua into a wxWidgets application, using templates was a bit of a no no (you can read cross-platform issues on the wxWidgets site).

# Starting with Lua
- First, you can download Lua from the official site Lua.org. At the time of writing, the latest version was 5.02. Lua comes ready to be built with any ANSI C compiler. The whole library is ANSI C compliant. After downloading the code it is quite easy to build a library (I personally stick to a static library for it). Seeing that we wanted to work in the C++ world we needed to convert the headers into C++. I created a new header file:
```lua
#ifndef __LUA_INC_H__
#define __LUA_INC_H__

extern "C"
{
   #include "lualib/lua.h"
   #include "lualib/lauxlib.h"
   #include "lualib/lualib.h"
}

#endif // __LUA_INC_H__
```
- This file includes all the Lua components necessary for Lua. Now you can just include the header (luainc.h) as per normal in C++ files. To start with the easiest, create a console project so that you can see the print outs from Lua.

# Lua problems with C++
- Lua is written in C, the whole Lua API is C based. Hence converting Lua into the C++ world would seem rather difficult, but Lua does provide abilities to do this. I have read many reports saying that Lua cannot be used with classes but through a bit of manipulation this can be achieved.

## Embedding Lua
- To embed Lua is quite easy. There is a lot of documentation listing the C-API for Lua so I am not going to go through that, but just want to give you the basic points. To control the running of Lua we create a CLuaVirtualMachine class. In my opinion a virtual machine is just there to interact with Lua on loading and running files as well as controlling the state. Many probably disagree, but that is worth my 5 cents. So our VM can load files and outside classes can get hold of the state in order to get things off and onto the Lua stack.

# Scripting with Lua
- In my application the script is there to provide "answers" to the running program. Hence the script is a collection of functions. Lua provides lots of examples of how to write scripts but a simple "hello world" would be like the following:
```lua
-- Lua Hello World (test.lua)
function helloWorld ()
   io.write ("hello World")
end
```
- The io.write is an aux library loaded into Lua. To get this script to run embedded in a program we have the following:
```lua
int iErr = 0;
lua_State *lua = lua_open ();  // Open Lua
luaopen_io (lua);              // Load io library
if ((iErr = luaL_loadfile (lua, "test.lua")) == 0)
{
   // Call main...
   if ((iErr = lua_pcall (lua, 0, LUA_MULTRET, 0)) == 0)
   { 
      // Push the function name onto the stack
      lua_pushstring (lua, "helloWorld");
      // Function is located in the Global Table
      lua_gettable (lua, LUA_GLOBALSINDEX);  
      lua_pcall (lua, 0, 0, 0);
   }
}
lua_close (lua);
```
- You should now see "hello World" printed on the console. OK, now we know how to call Lua functions. Now we will make Lua call C functions. What we have to do is register the function with Lua. For simplicity we create another printing function:
```lua
static int printMessage (lua_State *lua)
{
   assert (lua_isstring (lua,1));

   const char *msg = lua_tostring (lua, 1);

   // debug output
   cout << "script: " << msg << endl;
   return 0;
}

...
luaopen_io (lua);       // Load io library
// setup global printing (trace)
lua_pushcclosure (lua, printMessage, 0);
lua_setglobal (lua, "trace");
...
```
- And our script becomes:
```lua
-- Lua Hello World (test.lua)
function helloWorld ()
   io.write ("hello World")
   trace ("trace working now :)")
end
```
- You will now see "hello Worldscript: trace working now :)" printed out. So how does this help us?

# Getting into C++
- We have now seen how to get Lua call C functions but C is a long way from C++. The major thing about calling a C++ function is that you have to know the object you are referring to (i.e. this pointer). In the above code, you must have noticed that Lua stores all its functions in the LUA_GLOBALSINDEX table. In fact if you read the documentation you will find that most things in Lua are table based. This points us to the idea of storing our object in a Lua table. For a synergy with C++, we will call the table "this", thus indicating C++.
- Firstly our script changes to show the existence of the "this" table. The script does become slightly more complicated but is still easy enough to code. The major difference is that the functions now live in the "this" table rather than in the global table. The C++ code takes care of which "this" table is in operation. Also each script function has to pass the "this" table around if they want to access non-global functions. Our Hello World now becomes:
```lua
function this.helloWorld (this)
   io.write ("hello World")
   trace ("trace working now :)")
end
```
- For this you will see that the script can still call the global C functions.
- To start the C++ part, we need a few helpers to get us on our way. The first is a CLuaScript class. This class is for user classes to inherit from when they want to run the scripting functions. This class allows users to register C++ functions (methods) to Lua. The CLuaScript contains the reference to the "this" table as well. The reference is used to get hold of the "this" table later on when needed. The next helper class is CLuaThis. This class helps to control, which "this" table is currently being used by Lua.
- Every time a new CLuaScript is created, it creates a new table in Lua. This table is then stored in a global table called the registry. The registry is a persistent table across function calls. The "this" table is kept by means of a reference. With the reference we can push the table onto the stack when we need it. When the script is compiled, Lua places the helloWorld function in the "this" table. Lua knows about the "this" table because CLuaThis has told Lua before the compile where the "this" table was. The job of the "this" table is to keep all the functions together for the CLuaScript object. Each CLuaScript now has its own "this" table and bang we have object orientated Lua.

# Now what?
- Now that we have the theory, the trouble is how to put that into practice. Seeing that Lua can only call C functions (or static members of classes) we need a way of converting that to C++. Lua provides us with an ability to register a variable with the calling function. This allows us to be very cunning while registering our functions with Lua. In fact, we do not actually register the functions but register the index look-ups for them.

## Getting our hands dirty
- When we create a CLuaScript object we need to create a table and store the current this pointer in the table at index 0. This way when the script calls our C function we will be able to get the object pointer relating to the call. Hence the constructor:
```lua
lua_newtable (state);
m_iThisRef = luaL_ref (state, LUA_REGISTRYINDEX);

// Save the "this" table to index 0 of the "this" table
CLuaRestoreStack rs (vm);
lua_rawgeti (state, LUA_REGISTRYINDEX, m_iThisRef);
lua_pushlightuserdata (state, (void *) this);
lua_rawseti (state, -2, 0);
```
- You will notice a CLuaRestoreStack class there. This is just a class to ensure that the Lua stack is balanced on the exit. It is useful because then you can be lazy and not worry about making sure you leave the stack as you found it :)
- Now comes the compiling of files. We need to load the correct "this" table to the stack before we compile the script. In the constructor of CLuaThis class we have:
```lua
// Save the old "this" table
lua_getglobal (state, "this");
m_iOldRef = luaL_ref (state, LUA_REGISTRYINDEX);

// replace it with our new one
lua_rawgeti(state, LUA_REGISTRYINDEX, iRef);
lua_setglobal (state, "this");
```
- This saves the previous reference to a "this" table and loads the reference of our new one. Then in the destructor we return the stack. This is done so that the functions are all stored in the right table. Our compiling code then becomes:
```lua
CLuaThis luaThis (m_vm, m_iThisRef); // Make available to 
                                     // correct "this" table
                                     
m_vm.RunFile (strFilename);          // Compile the file
```
- After all this we come to registering those C++ functions. We always register the same C function with Lua for each C++ function. The difference is that each time we register with a unique index. This index is sent to the CLuaScript callback function. So hence the registering with Lua looks like this:
```lua
iMethodIdx = ++m_nMethods;

// Register a function with the lua script. 
// Added it to the "this" table
lua_rawgeti (state, LUA_REGISTRYINDEX, m_iThisRef);

// Push the function and parameters
lua_pushstring (state, strFuncName);
lua_pushnumber (state, (lua_Number) iMethodIdx);
lua_pushcclosure (state, LuaCallback, 1);
lua_settable (state, -3);
```
- You will notice that the function is stored in the "this" table and not globally. So now every time you want to call a function from a script you need to refer to the table. Now say we register a function called "hello" in Lua, our script would access it by:
```lua
function this.helloWorld (this)
   io.write ("hello World")
   trace ("trace working now :)")
   this:hello ()
end
```

# Using the code
## CLuaScript
- The first class to consider is the CLuaScript. You need to inherit your scripting class from it and overload the ScriptCalling and HandleReturns methods. The base code calls ScriptCalling each time the script calls one of the classes' methods. An index to the method is passed in as well. The HandleReturns method is called if there are any returns from the script that needs to be handled. The function name that is returning the values is passed to this. The CLuaScript base has the ability of sending parameters (int, float and string) to script functions.

## CLuaVirtualMachine
- The next class is CLuaVirtualMachine. You will only require one of these (unless you have other requirements). A test program would have the following structure:
```lua
class CMyScript : public CLuaScript
{
public:
   CMyScript (CLuaVirtualMachine& vm) : CLuaScript (vm)
   {
      m_iMethodBase = RegisterFunction ("hello1");
      RegisterFunction ("hello2");
      RegisterFunction ("hello3");
   }

   ...
   int ScriptCalling (CLuaVirtualMachine& vm, 
                                  int iFunctionNumber)
   {
      switch (iFunctionNumber - m_iMethodBase)
      {
      case 0:
         return Hello1 (vm);
      case 1:
         return Hello2 (vm);
      case 2:
         return Hello3 (vm);
      }

      return 0;
   }
   ...
   int Hello2 (CLuaVirtualMachine& vm)
   {
      lua_State *state = (lua_State *) vm;

      int iNumber = (int) lua_tonumber (state, -1);
      printf ("Hellow (2) -> %d\n", iNumber);
      return 0;
   }
   ...
   void HandleReturns (CLuaVirtualMachine& vm, 
                                const char *strFunc);
   ...
};

void main (void)
{
   CLuaVirtualMachine vm;
   vm.InitialiseVM ();
   ...
   CMyScript ms (vm);
   ms.CompileFile ("test.lua");
   ...
   ms.SelectScriptFunction ("CountAndCall");
   ms.AddParam (2);
   ms.Go ();
   ...
}
```

## The others
- There are other classes as mentioned in the discussion. There is a debugging class as well, but I do not really use it much but when things go wrong it comes in handy to see where the script is going. The sample shows how it is used.

# History
v1.0 - Ah..., the first version. Never buy any software that is version 1. Bugs will be there :)
v1.01 - Corrected CLuaThis class to get the "this" table before setting up the new one.
# License
This article, along with any associated source code and files, is licensed under The Code Project Open License (CPOL)