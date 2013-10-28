print "Loading bindings" 
WALL_Bindings = {}

for i = 0, 9 do
	WALL_Bindings[("Alt"..i)] = function () 
		print "No bind aviable" 
	end
end

function bind(a,b)
	WALL_Bindings[a] = b
end
