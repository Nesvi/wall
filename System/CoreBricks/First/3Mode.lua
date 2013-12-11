class.new "Mode"

GlobalModes = {}

function Mode:initialize(str)
	_G[str] = self
	self.name = str
	self.binds = {}
end

function Mode:addGlobalMode()
	GlobalModes[self.name]=self
end

function Mode:removeGlobalMode()
	self.onRemove();
	self:removeBinds()
	GlobalModes[self.name]=nil
end

function Mode:addBind(key, lambda)
	self.binds[#self.binds+1] = {key,lambda}
	bind(key,lambda)
end

function removeBinds()
	for i=1, #self.binds do
		if WALL_Bindings[self.binds[i][1]] == self.binds[i][2] then
			WALL_Bindings[self.binds[i][1]] = nil
		end	
		
	end
end

function Mode:onStart()
end

function Mode:onRemove()
end
