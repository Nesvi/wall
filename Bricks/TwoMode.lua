--With this mode you can alternate between console and the internal workBuffer with Alt+1 and Alt+2
Mode:new "TwoMode" 

TwoMode:addGlobalMode();

function TwoMode:onStart()
	self.buffer = Buffer:new()
	self.buffer:setEditable(true)
	self.buffer:setBuffer()
	self.buffer:openFile("/home/nesvi/thing.lua")
	
	--Set up bindings
	self:addBind("Alt1", self.toConsole)
	self:addBind("Alt2", self.toBuffer)
end

function TwoMode:toConsole()
	wallConsole:setBuffer()
end

function TwoMode:toBuffer()
	TwoMode.buffer:setBuffer()
end

function TwoMode:onRemove()
	log "Two mode disabled" 
end

log "Two Mode loaded"
