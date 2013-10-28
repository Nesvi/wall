print "Loading example extension" 
numeroDePato = 0;

WALL_Bindings.Alt1 = function ()
		
	currentBuffer:insertInCursor("Pato numero " .. numeroDePato .. "\n");
	numeroDePato = numeroDePato + 1;
end

--WALL_Bindings.Alt1()
