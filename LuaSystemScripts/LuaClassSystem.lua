--Declaraciones iniciales

system_class_instances = {}
class = {}

--Instance storage

system_class_instances.add = function( newInstance ) 

	system_class_instances[#system_class_instances + 1] = newInstance
	return #system_class_instances
end

--Class storage

class.new = function() --Creates a new class
	newClass = {}
	class[#class+1] = newClass
	function newClass:new(...)
		newInstance = {}

		for key,value in pairs(self) do 
			newInstance[key] = value 
		end

		newInstance.lua_system_id = system_class_instances.add(newInstance)
		newInstance:constructor(...)

		return newInstance
	end
	
	return newClass
end
