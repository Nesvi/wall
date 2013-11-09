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
  luaL_dostring(L,(std::string("wallFolder=\"")+wallFolder+std::string("\"")).c_str());
  
  luaL_dofile(L, (wallFolder+std::string("/System/LuaClassSystem.lua")).c_str());
  luaL_dofile(L, (wallFolder+std::string("/System/Core.lua")).c_str());
  luaL_dofile(L, (wallFolder+std::string("/System/Bindings.lua")).c_str());
  luaL_dofile(L, (wallFolder+std::string("/System/Bricks.lua")).c_str());
}

void Lua::Main(){

  luaL_dofile(L,"./System/Main.lua");

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



