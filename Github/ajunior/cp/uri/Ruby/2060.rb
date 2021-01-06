n = gets.to_i

result = {
    2 => 0,
    3 => 0,
    4 => 0,
    5 => 0
}

arr = gets.chomp.split

arr.each do |n|
   n = n.to_i

   if n % 2 == 0
     result[2] += 1
   end

   if n % 3 == 0
     result[3] += 1
   end

   if n % 4 == 0
     result[4] += 1
   end

   if n % 5 == 0
     result[5] += 1
   end
end

result.map do |m, v|
  puts "#{v} Multiplo(s) de #{m}"
end