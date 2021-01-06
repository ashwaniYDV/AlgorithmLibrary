while (true) do
    x, m = io.read("*number", "*number")
    if (x == 0 and m == 0) then break end
    print(x*m)
end