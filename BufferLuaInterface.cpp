#include "BufferLuaInterface.h"
#include "ConvertInt.h"
#include "BufferManager.h"

//Estáticos
//Buffer* BufferLuaInterface::currentInstance;
std::vector<Buffer*> BufferLuaInterface::bufferInstances;

int LuaBuffer_sayHello(lua_State* L){
  BufferLuaInterface::getInstance(L)->sayHello();
  return 0;
}

int LuaBuffer_getText(lua_State* L){
  lua_pushstring(L,BufferLuaInterface::getInstance(L)->getText().c_str());
  return 1;  
}

int LuaBuffer_setText(lua_State* L){
  BufferLuaInterface::getInstance(L)->setText(std::string(lua_tostring(L,1)));
  return 0;
}

int LuaBuffer_setLanguage(lua_State* L){
  BufferLuaInterface::getInstance(L)->setLanguage(std::string(lua_tostring(L,1)));
  return 0;
}

int LuaBuffer_insertInCursor(lua_State* L){
  
  BufferLuaInterface::getInstance(L)->insertInCursor(std::string(lua_tostring(L,1)));		    	 
  return 0;
}

int LuaBuffer_moveCursor(lua_State* L){
  /*std::cout << "Argumento1=" << lua_tonumber(L,1) 
	    <<"Argumento2=" << lua_tonumber(L,2) << std::endl;
  */
  BufferLuaInterface::getInstance(L)->moveCursor(lua_tonumber(L,1),
						 lua_tonumber(L,2)
						 );				
  return 0;
}

int LuaBuffer_save(lua_State* L){
  BufferLuaInterface::getInstance(L)->save();
  return 0;
}

int LuaBuffer_getCursorLine(lua_State* L){
  lua_pushnumber(L,BufferLuaInterface::getInstance(L)->getCursorLine());
  return 1;
}


int LuaBuffer_newBufferCInstance(lua_State* L){

  Buffer* aux = BufferManager::newBuffer();  
  aux->lua_id = lua_tonumber(L,1);
  lua_pushnumber(L,BufferLuaInterface::addNewInstance(aux));
  return 1;
}

int LuaBuffer_newBufferCInstance2(lua_State* L){

  Buffer* aux = BufferManager::newBuffer(lua_tostring(L,2), lua_tostring(L,3));
  aux->lua_id = lua_tonumber(L,1);
  //std::cout << "La lua_id es :" << aux->lua_id << std::endl; 
  lua_pushnumber(L,BufferLuaInterface::addNewInstance(aux));
  return 1;
}

int setBuffer(lua_State* L){
  BufferManager::setBuffer(*BufferLuaInterface::getInstance(L));
  return 0;
}

//Métodos
void BufferLuaInterface::init(){//bad name
  //Declarar funciones de C en Lua
  lua_register(Lua::L, "newBufferCInstance", LuaBuffer_newBufferCInstance);
  lua_register(Lua::L, "newBufferCInstance2", LuaBuffer_newBufferCInstance2);

  //Funciones globales
  lua_register(Lua::L, "WALL_setBuffer", setBuffer);

  //Metodos de Buffer
  lua_register(Lua::L, "WALL_Buffer_sayHello", LuaBuffer_sayHello);
  lua_register(Lua::L, "WALL_Buffer_getText", LuaBuffer_getText);
  lua_register(Lua::L, "WALL_Buffer_setText", LuaBuffer_setText);
  lua_register(Lua::L, "WALL_Buffer_setLanguage", LuaBuffer_setLanguage);
  lua_register(Lua::L, "WALL_Buffer_save", LuaBuffer_save);
  lua_register(Lua::L, "WALL_Buffer_insertInCursor", LuaBuffer_insertInCursor);
  lua_register(Lua::L, "WALL_Buffer_moveCursor", LuaBuffer_moveCursor);
  lua_register(Lua::L, "WALL_Buffer_getCursorLine", LuaBuffer_getCursorLine);

  //Cargar la clase Buffer
  luaL_dofile( Lua::L, "./LuaSystemScripts/BufferClass.lua");
  luaL_dofile( Lua::L, "./LuaSystemScripts/BufferManager.lua");
  
}

int BufferLuaInterface::addNewInstance(Buffer* in){

  bufferInstances.push_back( in );
  return bufferInstances.size()-1;

}

Buffer* BufferLuaInterface::getInstance(lua_State* L){
  lua_getglobal(L, "WALL_c_id");
  int number = lua_tonumber(L,-1);
  //std::cout << "Intentando acceder a la instancia de C " << number << std::endl;
  return bufferInstances[number];
}

