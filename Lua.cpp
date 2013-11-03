#include "Lua.h"

lua_State* Lua::L;

Lua::Lua(){}

void Lua::init(){
  L = luaL_newstate();
  luaL_openlibs(L);

  std::ifstream conf("/etc/wall/wallfolder");
  std::string wallFolder;
  conf >> wallFolder;
  conf.close();

  luaL_dofile(L, (wallFolder+std::string("/LuaSystemScripts/LuaClassSystem.lua")).c_str());
  luaL_dofile(L, (wallFolder+std::string("/LuaSystemScripts/Bindings.lua")).c_str());
  luaL_dofile(L, (wallFolder+std::string("/LuaSystemScripts/Core.lua")).c_str());
  luaL_dofile(L, (wallFolder+std::string("/Extensions/Extensions.lua")).c_str());
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



