x = io.read("*number")
y = io.read("*number")

if (x > y) then
    local tmp = x
    x = y
    y = tmp
end

sum = 0
while (x <= y) do
    if not (x % 13 == 0) then sum = sum + x end
    x = x + 1
end

print(sum)