extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <iostream>
#include <fstream>
#include <string>

class Lua{

private:
  
public:
  Lua();
  ~Lua();

  static lua_State *L;

  static void loadScript(const char* );
  static lua_State* getL();
  static void init();
  static void Main();
};
