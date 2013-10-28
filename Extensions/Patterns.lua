print "Loading patterns extension" 

WALL_Bindings.Alt7 = function ()
	print "llamado" 		
	local text = currentBuffer:getText()

	vars = {}
	local b = 0
	while true do
		i, b, var = string.find(text,"%s*(%a+)%s*[=]%s*.-[\n;]",b+1)--%s*.-%n" , i+1)	
		print (var)
		if b == nil then print "Break" ; break end
	end	
	
end

