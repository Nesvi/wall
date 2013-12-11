
function Buffer:setEditable(arg1)
	self._editable = arg1
	return QBBuffer_setEditable(self.C_userdata,arg1)
end


function Buffer:setBuffer()
	if self._editable == nil then self._editable = true end
	self:setEditable(self._editable)
	currentBuffer = self
	return QBBuffer_setBuffer(self.C_userdata)
end

--Buffer.path = nil

function Buffer:openFile(path)

	if self ~= wallConsole then
		local result = fileToString(path)
		if result ~= nil then
			self.path = path
			self:setText(result) 
		else
			log "Brick not found"
		end
	else
		log "You cannot open a file in the console buffer"
	end	
end

function Buffer:save()
	if self.path ~= nil then
		stringToFile(self:getText(), self.path)		
		log "File saved"
	else
		log "There are no path aviable for this buffer, set a valid path to save it"
	end
end

function Buffer:execute()
	loadstring(self:getText())()
end

print "BufferExtension loaded"
