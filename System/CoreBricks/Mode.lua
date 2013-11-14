class.new "Mode"

GlobalModes = {}

function Mode:initialize(str)
	_G[str] = self
	self.name = str
end

function Mode:addGlobalMode()
	GlobalModes[self.name]=self
end

function Mode:removeGlobalMode()
	GlobalModes[self.name]=nil
end

function Mode:onStart()
end

