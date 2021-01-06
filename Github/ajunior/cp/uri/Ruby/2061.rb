arr = gets.chomp.split

fechou = 0.to_i
clicou = 0.to_i

arr.each do |v|
  fechou += 1 if v.eql?("fechou")
  clicou += 1 if v.eql?("clicou")
end

x = arr[0].to_i + fechou.to_i - clicou.to_i

puts "#{x}"

