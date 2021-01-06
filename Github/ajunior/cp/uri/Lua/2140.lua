while true do
    local price, paid = io.read("*number", "*number")
    if (price == 0 and paid == 0) then break end
    local change = paid - price
    local bills = 0
    
    if (change >= 100) then
        bills = change / 100
        change = change % 100
    end
    
    if (change >= 50) then
        bills = bills + (change / 50)
        change = change % 50
    end

    if (change >= 20) then
        bills = bills + (change / 20)
        change = change % 20
    end

    if (change >= 10) then
        bills = bills + (change / 10)
        change = change % 10
    end
    
    if (change >= 5) then
        bills = bills + (change / 5)
        change = change % 5
    end
    
    if (change >= 2) then
        bills = bills + (change / 2)
        change = change % 2
    end

    if (math.floor(bills) == 2) then 
        print("possible") 
    else
        print("impossible")
    end 
end
