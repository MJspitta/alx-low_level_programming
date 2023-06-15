#!/usr/bin/python3
def is_pdrome(n):
    return str(n) == str(n)[::-1]

big_pdrome = 0
for i in range(100, 1000):
    for j in range(i, 1000):
        mul = i * j
        if is_pdrome(mul) and mul > big_pdrome:
            big_pdrome = mul

with open("102-result", "w") as file:
    file.write(str(big_pdrome))
