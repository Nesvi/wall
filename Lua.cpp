#include "Lua.h"

lua_State* Lua::L;

Lua::Lua(){}

void Lua::init(){
  L = luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L, "./LuaSystemScripts/LuaClassSystem.lua");
  luaL_dofile(L, "./LuaSystemScripts/Bindings.lua");
  luaL_dofile(L, "./Extensions/Extensions.lua");
}

void Lua::Main(){

  luaL_dofile(L,"./LuaSystemScripts/Main.lua");

}
void Lua::loadScript(const char* filename){
  
  luaL_dofile(L, filename);

}

lua_State* Lua::getL(){
  return L;
}

Lua::~Lua(){

 lua_close(L);

}



