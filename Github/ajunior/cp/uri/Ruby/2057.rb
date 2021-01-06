arr = gets.chomp.split

s = arr[0].to_i
t = arr[1].to_i
f = arr[2].to_i

if (s+t+f > 23)
    h = (s+t+f) - 24
elsif (s+t+f < 0)
    h = (s+t+f) + 24
else
    h = (s+t+f)
end

puts "#{h}"