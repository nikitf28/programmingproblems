
table = [[i*j for j in range(1, 11) ] for i in range (1, 11)]

for row in table:
    for symb in row:
        print(symb, end=" ")
    print()
