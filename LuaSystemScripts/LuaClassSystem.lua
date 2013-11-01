--Declaraciones iniciales

system_class_instances = {}
class = {}

--Instance storage

system_class_instances.add = function( newInstance ) 

	system_class_instances[#system_class_instances + 1] = newInstance
	return #system_class_instances
end

--Class storage

class.new = function(...) --Creates a new class
	local arg = {...}
	newClass = {}
	class[#class+1] = newClass
	_G[arg[1]] = newClass
	
	for i=2, #arg do
		for key,value in pairs(arg[i]) do 
			newClass[key] = value 
		end
	end
		
	function newClass:new(...)
		newInstance = {}

		for key,value in pairs(self) do 
			newInstance[key] = value 
		end

		newInstance.system_id = system_class_instances.add(newInstance)
		newInstance:initialize(...)

		return newInstance
	end
	
	return newClass
end


