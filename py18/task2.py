n, m = map(int, input().split())

data = [[0 for j in range(n)] for i in range(n)]

for i in range(m):
    x, y = map(int, input().split())
    data[x - 1][y - 1] = 1
    data[y - 1][x - 1] = 1

for i in range(n):
    for j in range(m):
        print(data[i][j], end=" ")
    print()