print "Loading main" 
--currentBuffer = Buffer:new("test.lua","/home/nesvi/Escritorio/")
currentBuffer = Buffer:new()
currentBuffer:setBuffer()
--[[
currentBuffer:sayHello()
system_class_instances[1]:sayHello()
currentBuffer:setText("function onLoad()\n \tprint \"Hello\" \nend")
print(currentBuffer:getText())
]]
