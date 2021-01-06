while true do
    month, day = io.read("*number", "*number")
    if (month == nil) then break end

    if (month == 12 and day == 25) then print("E natal!")
    elseif (month == 12 and day == 24) then print("E vespera de natal!")
    elseif (month == 12 and day > 25) then print("Ja passou!")
    else
        local month_a = {31,29,31,30,31,30,31,31,30,31,30,31}
        local left = 0
        for i = month, 11 do
            left = left + month_a[i]
        end
        print("Faltam " .. left + (25 - day) .. " dias para o natal!") 
    end
end