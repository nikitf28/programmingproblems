def dfs(point):
    #print(data)
    #print(max_way)
    for i in range(n):
        if data[point][i] != -1:
            #print(max_way[0])
            if max_way[0] < data[point][i]:
                max_way[0] = data[point][i]
                max_way[1] = 1
                max_way[2] = point
                max_way[3] = i
            elif max_way[0] == data[point][i]:
                max_way[1] += 1
            data[point][i] = -1
            dfs(i)

max_way = [0, 0, 0, 0]

n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
    dfs(i)


#print(max_way)
if max_way[1] == 1:
    print(max_way[2] + 1, max_way[3] + 1)
else:
    print("No exit!")