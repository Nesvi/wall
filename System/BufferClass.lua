print "Loading Buffer class"

WALL_Buffers = {}
Buffer = class.new();

function Buffer:constructor(name,path)
	--[[
	if name == nil then
		self.C_system_id = newBufferCInstance(self.lua_system_id);
	else
		self.C_system_id = newBufferCInstance2(self.lua_system_id, name, path);
	end
	]]
	self.C_userdata = WALL_Buffer_newBufferUserData()
	--print ("Creado un objeto con indice C"..self.C_system_id)
	--print ("Creado un objeto con indice Lua"..self.lua_system_id)
	WALL_Buffers[#WALL_Buffers + 1] = self
end

function Buffer:sayHello()
	WALL_c_id = self.C_system_id;
	--print ("Pasando WALL_c_id" .. WALL_c_id)
	WALL_Buffer_sayHello();
end

function Buffer:setText(str)
	WALL_c_id = self.C_system_id;	
	--print ("Pasando WALL_c_id" .. WALL_c_id)
	WALL_Buffer_setText(str)
end

function Buffer:getText()
	WALL_c_id = self.C_system_id;	
	--print ("Pasando WALL_c_id" .. WALL_c_id)	
	return WALL_Buffer_getText(self.C_userdata)
end

function Buffer:insertInCursor(beg)
	WALL_c_id = self.C_system_id;	
	WALL_Buffer_insertInCursor(beg)
end

function Buffer:save()
	WALL_c_id = self.C_system_id;		
	WALL_Buffer_save()
end

function Buffer:moveCursor(a,b)
	WALL_c_id = self.C_system_id;		
	WALL_Buffer_moveCursor(a,b)
end

function Buffer:getCursorLine()
	WALL_c_id = self.C_system_id
	return WALL_Buffer_getCursorLine()
end

function Buffer:setLanguage(lang)
	WALL_c_id = self.C_system_id
	return WALL_Buffer_setLanguage(lang)
end
	
