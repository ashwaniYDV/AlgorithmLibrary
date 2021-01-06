n = io.read("*number")
print(string.format("%.1f", (math.pow((1+math.sqrt(5))/2, n) - math.pow((1-math.sqrt(5))/2, n))/math.sqrt(5)))