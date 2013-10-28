#ifndef _BufferLuaInterface
#define _BufferLuaInterface

#include "Buffer.h"
#include "Lua.h"
/*
int LuaBuffer_getY(lua_State *L);
int LuaBuffer_getX(lua_State *L);
int LuaBuffer_setPosition(lua_State *L);

*/

int LuaBuffer_sayHello(lua_State *L);
int LuaBuffer_newBufferCInstance(lua_State *L);

class BufferLuaInterface {

private:
 

public:
  static std::vector<Buffer*> bufferInstances;
  //static Buffer* currentInstance;
  
  static int addNewInstance(Buffer* );
  static void init();
  static Buffer* getInstance(lua_State*);

/*
  static void setInstance( Buffer* );
  static void update();
  static void initGameEngine();
  static void loadMain();*/
};

#endif
