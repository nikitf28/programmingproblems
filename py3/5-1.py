n, m = input().split()
n, m = int(n), int(m)

arr = []

for i in range(0, n):
    st = input()
    br = []
    for l in st:
        br.append(l)
    arr.append(br)

#print(arr)

for i in range(0, n - 1):
    for j in range(0, m - 1):
        su = 0
        if arr[i][j] == '*':
            su += 1
        if arr[i][j+1] == '*':
            su += 1
        if arr[i+1][j] == '*':
            su += 1
        if arr[i+1][j+1] == '*':
            su += 1
        if su == 3:
            arr[i][j] = '*'
            arr[i][j+1] = '*'
            arr[i+1][j] = '*'
            arr[i+1][j+1] = '*'

for i in range(0, n):
    for j in range(0, m):
        print(arr[i][j], end='')
    print()
