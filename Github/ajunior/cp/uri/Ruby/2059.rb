arr = gets.chomp.split

p = arr[0].to_i
j1 = arr[1].to_i
j2 = arr[2].to_i
r = arr[3].to_i
a = arr[4].to_i

if r == 1 and a == 0
  puts "Jogador 1 ganha!"
elsif r == 1 and a == 1
  puts "Jogador 2 ganha!"
else
  if p == 1
    if (j1 + j2) % 2 == 0
      puts "Jogador 1 ganha!"
    else
      puts "Jogador 2 ganha!"
    end
  end

  if p == 0
    if (j1 + j2) % 2 == 0
      puts "Jogador 2 ganha!"
    else
      puts "Jogador 1 ganha!"
    end
  end
end




