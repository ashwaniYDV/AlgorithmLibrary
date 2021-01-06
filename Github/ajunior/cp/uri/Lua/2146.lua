while true do
    line = io.read("*number")
    if line == nil then break end
    print(line - 1)
end