#ifndef _BufferLuaQB
#define _BufferLuaQB
extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}



#include "Buffer.h"

class BufferLuaQB{
	public:
		static Buffer* getInstance(lua_State* L);
		static void load(lua_State* L);
};
#endif