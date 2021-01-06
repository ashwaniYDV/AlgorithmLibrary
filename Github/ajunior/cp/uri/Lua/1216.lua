sum = 0
count = 0

while true do
    local line = io.read()
    if line == nil then break end
    print(line)
    
    local n = io.read("*number")
    sum = sum + n
    print(sum)
    count = count + 1
    print(count)
end

print(sum/count)
