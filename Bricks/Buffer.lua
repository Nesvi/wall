class.new "Buffer"

function Buffer:initialize()
	self.C_userdata=QBBuffer_newUserData()
end
function Buffer:moveCursor(arg1,arg2)
	return QBBuffer_moveCursor(self.C_userdata,arg1,arg2)
end
function Buffer:setText(arg1)
	return QBBuffer_setText(self.C_userdata,arg1)
end
function Buffer:save()
	return QBBuffer_save(self.C_userdata)
end
function Buffer:setEditable(arg1)
	return QBBuffer_setEditable(self.C_userdata,arg1)
end
function Buffer:insertInCursor(arg1)
	return QBBuffer_insertInCursor(self.C_userdata,arg1)
end
function Buffer:sayHello()
	return QBBuffer_sayHello(self.C_userdata)
end
function Buffer:setLanguage(arg1)
	return QBBuffer_setLanguage(self.C_userdata,arg1)
end
function Buffer:setBuffer()
	return QBBuffer_setBuffer(self.C_userdata)
end
function Buffer:getText()
	return QBBuffer_getText(self.C_userdata)
end
function Buffer:getCursorLine()
	return QBBuffer_getCursorLine(self.C_userdata)
end
