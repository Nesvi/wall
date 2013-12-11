function log(str)
	time = os.date("*t")
	wallConsole:setText(wallConsole:getText() ..time.hour .. ":" .. time.min .. ":" .. time.sec.." -> "..str.."\n")
end

function initConsole()
	print "Initalizing console"
	wallConsole = Buffer:new()
	wallConsole:setBuffer()
	wallConsole:setEditable(false)
	log("**********Log console**********")
end

initConsole()
print "Log loaded"
