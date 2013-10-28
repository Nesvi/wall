print "Loading Basics extension"

function save()
	currentBuffer:save()
end

function execute()
	print "WALL->Executing"
	loadstring(currentBuffer:getText())()
end

function loadExtension(ext)
	print "WALL->Loading extension"
	dofile("./Extensions/"..ext .. ".lua")
end

function openExtension(ext)
	open("./Extensions/" .. ext .. ".lua")
end

function open(path)
	print("WALL-> Opening " .. path)
	i, b, path,file = string.find(path,"(.+/)(.+)")
	local myBuffer = Buffer:new(file, path)
	i, b, lang = string.find(file,"%a+%.(%a+)")
	print(lang)
	myBuffer:setLanguage( lang )
	setBuffer(myBuffer)
end

function openfile(file)
	--Open a file from the folder of the current buffer 
end

function nextBuffer()
	print "WALL->Next buffer"
	local index,i = -1
	
	for i = 1, #WALL_Buffers do
		if WALL_Buffers[i] == currentBuffer then index = i +1 ; break end
	end
	
	if( index > #WALL_Buffers ) then index = 1 end
	
	setBuffer(WALL_Buffers[index])

end

function previousBuffer()
	print "WALL->Previous buffer"
	local index,i = -1
	
	for i = 1, #WALL_Buffers do
		if WALL_Buffers[i] == currentBuffer then index = i -1 ; break end
	end
	
	if( index < 1 ) then index = #WALL_Buffers end
	
	setBuffer(WALL_Buffers[index])

end

function getLuaVariables()

	print "llamado" 		
	local text = currentBuffer:getText()

	vars = {}
	local b = 0
	while true do
		i, b, var = string.find(text,"%s*(%a+)%s*[=]%s*.-[\n;]",b+1)--%s*.-%n" , i+1)	
		if b == nil then break end
		print (var)
	end		

end

bind("Alt1",previousBuffer)
bind("Alt2",nextBuffer)
bind("Alt3",save)


