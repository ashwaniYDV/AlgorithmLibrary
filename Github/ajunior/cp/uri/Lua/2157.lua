start, last = io.read("*number","*number")
str = ""

for i = start, last do
    str = str .. i
    i = i+1
end
print(str)
j = #str
print(#str)
strrev = ""
while (j > 0) do
    strrev = strrev .. str[j]
    j = j-1
end
print(str)
