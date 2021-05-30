def dfs(point, color):
    #print(visited, color, point)
    if visited[point] != 0:
        return
    visited[point] = color
    for i in range(n):
        if data[point][i] == 1:
            dfs(i, color)


n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

visited = [0 for i in range(n)]

for point in range(n):
    dfs(point, point+1)

colors = []

for color in visited:
    if color not in colors:
        colors.append(color)

#print(colors)

print(len(colors))