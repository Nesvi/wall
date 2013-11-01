#include "BufferLuaQB.h"

int BufferLuaQB_insertInCursor(lua_State* L){
	BufferLuaQB::getInstance(L)->insertInCursor(std::string(lua_tostring(L,2)));
	return 0;
}

int BufferLuaQB_getText(lua_State* L){
	lua_pushstring(L,BufferLuaQB::getInstance(L)->getText().c_str());
	return 1;
}

int BufferLuaQB_getCursorLine(lua_State* L){
	lua_pushnumber(L,BufferLuaQB::getInstance(L)->getCursorLine());
	return 1;
}

int BufferLuaQB_setText(lua_State* L){
	BufferLuaQB::getInstance(L)->setText(std::string(lua_tostring(L,2)));
	return 0;
}

int BufferLuaQB_save(lua_State* L){
	BufferLuaQB::getInstance(L)->save();
	return 0;
}

int BufferLuaQB_setBuffer(lua_State* L){
	BufferLuaQB::getInstance(L)->setBuffer();
	return 0;
}

int BufferLuaQB_moveCursor(lua_State* L){
	BufferLuaQB::getInstance(L)->moveCursor(lua_tonumber(L,2), lua_tonumber(L,3));
	return 0;
}

int BufferLuaQB_sayHello(lua_State* L){
	BufferLuaQB::getInstance(L)->sayHello();
	return 0;
}

int BufferLuaQB_setLanguage(lua_State* L){
	BufferLuaQB::getInstance(L)->setLanguage(std::string(lua_tostring(L,2)));
	return 0;
}

int BufferLuaQB_newUserData(lua_State* L){
	lua_pushlightuserdata(L,new Buffer());
	 return 1;
}
void BufferLuaQB::load(lua_State* L){
	lua_register(L,"QBBuffer_insertInCursor",BufferLuaQB_insertInCursor);
	lua_register(L,"QBBuffer_getText",BufferLuaQB_getText);
	lua_register(L,"QBBuffer_getCursorLine",BufferLuaQB_getCursorLine);
	lua_register(L,"QBBuffer_setText",BufferLuaQB_setText);
	lua_register(L,"QBBuffer_save",BufferLuaQB_save);
	lua_register(L,"QBBuffer_setBuffer",BufferLuaQB_setBuffer);
	lua_register(L,"QBBuffer_moveCursor",BufferLuaQB_moveCursor);
	lua_register(L,"QBBuffer_sayHello",BufferLuaQB_sayHello);
	lua_register(L,"QBBuffer_setLanguage",BufferLuaQB_setLanguage);
	lua_register(L,"QBBuffer_newUserData",BufferLuaQB_newUserData);
	luaL_dofile(L,"Buffer.lua");
}

Buffer* BufferLuaQB::getInstance(lua_State* L){
	return reinterpret_cast<Buffer*>(lua_touserdata(L,1));
}

