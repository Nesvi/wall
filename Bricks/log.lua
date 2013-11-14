function log(str)
	time = os.date("*t")
	wallConsole:insertInCursor(time.hour .. ":" .. time.min .. ":" .. time.sec.." -> "..str.."\n")
end

function initConsole()
	wallConsole = Buffer:new()
	wallConsole:setBuffer()
	wallConsole:setEditable(false)
	log("**********Log console**********")
end

print "Log loaded"
