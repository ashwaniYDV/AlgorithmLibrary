while (true) do
    x, y = io.read()
    if x == nil then break end

    sum = 0
    for i = 1, #y do
        sum = sum + tonumber(y[i])
    end

    if y % 3 == 0 then print(sum .. " sim") 
    else print(sum .. " nao") end
end