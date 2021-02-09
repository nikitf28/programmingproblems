import math

used = []

for num in range(1, 10001):

    if num in used:
        continue
    
    deli1 = []
    deli2 = []
    for de in range(1, num//2+1):
        if num % de == 0:
            deli1.append(de)
    num2 = 0
    for ch in deli1:
        num2 += ch

    for de in range(1, num2//2+1):
        if num2 % de == 0:
            deli2.append(de)

    num1 = 0

    for ch in deli2:
        num1 += ch

    #print(num)
    #print(deli1)
    #print(deli2)
    #print()

    if num1 == num and num1 != num2:
        print(num, num2)
        used.append(num)
        used.append(num2)
