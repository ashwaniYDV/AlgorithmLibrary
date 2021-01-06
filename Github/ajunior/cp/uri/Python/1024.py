w = list()
word = input()

index = len(word) - 1
while index >= 0:
    if word[index].isalpha():
        x = ord(word[index]) + 3
        w.append(chr(x))
    else:
        w.append(chr(ord(word[index])))
    index -= 1

print(w)
print(word[::-1])
