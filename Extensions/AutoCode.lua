print "Loading AutoCode example" 

--[[
WALL_Bindings.Alt2 = function ()

	local line = currentBuffer:getCursorLine()	
	currentBuffer:insertInCursor("if () then \n\n\t\n\nend")
	currentBuffer:moveCursor(line + 2, 1)
	--currentBuffer:moveCursor(2, 0)
	--currentBuffer:moveCursor(0,0)
end
]]

function autoIndent()

	local code = currentBuffer:getText()
	
	code = string.gsub( code, "\t","")
	code = string.gsub( code, "\n%s*\n","\n")
	
	print("---------------------------------------------------")
	
	
	print(code)

end

function check()
	print("ID del currentBuffer:" .. currentBuffer.C_system_id)
end

function write()
	--currentBuffer:setText("Written")
	--currentBuffer:insertInCursor("Written")
	currentBuffer:moveCursor(2,0)
end
