print "-->Loading Bricks"
function loadExtensions()
	local el = system("ls "..wallFolder.."/Bricks/*.lua")
	el = split(el,"%s")
	for i=1, #el do		
		dofile(el[i])	
	end
end

dcall(loadExtensions)

print "-->Bricks loaded"
