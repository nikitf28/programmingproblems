t = int(input())

for o in range(t):
    n, m = input().split()
    n = int(n)
    m = int(m)
    arr = [input().split() for i in range(n)]
    f = False
    #print(arr)
    for i in range(n - 1):
        for j in range(m - 1):
            su = 0
            if arr[i][j] == '1':
                su += 1
            if arr[i][j+1] == '1':
                su += 1
            if arr[i+1][j] == '1':
                su += 1
            if arr[i+1][j+1] == '1':
                su += 1
            if su == 0 or su == 4:
                print("NO")
                f = True
                break
        if f:
            break
    if not f:
        print("YES")
