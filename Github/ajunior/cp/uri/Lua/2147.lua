c = tonumber(io.read())
while true do
    if (c < 1) then break end
    local word = io.read()
    print(string.format("%.2f", #word * (1/100)))  
    c = c - 1
end