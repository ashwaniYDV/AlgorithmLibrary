n = io.read("*number")

for i = 1, n do
    h, m, o = io.read("*number", "*number", "*number")
    local s
    if (h <= 9) then s = "0" .. tostring(h) .. ":" else s = tostring(h) .. ":" end
    if (m <= 9) then s = s .. "0" .. tostring(m) else s = s .. tostring(m) end
    if (o == 1) then s = s .. " - A porta abriu!" else s = s .. " - A porta fechou!" end 
    print(s)
end 