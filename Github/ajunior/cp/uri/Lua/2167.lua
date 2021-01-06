n = io.read("*number")
past = -1

for i = 1, n do
    local next = io.read("*number")

    if (i == n and next >= past) then 
        print(0) 
        break
    end

    if (next >= past) then 
        past = next 
    else
        print(i)
        break
    end
end