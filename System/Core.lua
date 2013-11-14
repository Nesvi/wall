function system(a)
	local f = io.popen(a) -- runs command
	local l = f:read("*a") -- read output of command
	f:close()
	return l
end

--String helpers
function split(str, pat)
   local t = {} 
   local fpat = "(.-)" .. pat
   local last_end = 1
   local s, e, cap = str:find(fpat, 1)
   while s do
      if s ~= 1 or cap ~= "" then
	 table.insert(t,cap)
      end
      last_end = e+1
      s, e, cap = str:find(fpat, last_end)
   end
   if last_end <= #str then
      cap = str:sub(last_end)
      table.insert(t, cap)
   end
   return t
end

function dcall(lamb)
   local status, err = pcall(function() lamb(); end)
   if err ~= nil then
	print(err)
	print(debug.traceback())
	log(err)
	log(debug.traceback())
   end
end

function start()
	for k,v in pairs(GlobalModes) do
		v:onStart()
	end
end

function loadCoreBricks()
	local el = system("ls "..wallFolder.."/System/CoreBricks/*.lua")
	
	el = split(el,"%s")
	for i=1, #el do		
		dofile(el[i])	
	end
end

loadCoreBricks()
print "Core loaded"
