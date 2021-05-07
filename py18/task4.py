n, m = map(int, input().split())

data = [[] for i in range(n)]
colors = [0 for i in range(n)]


def dfs(point, color):
    for visit in data[point]:
        if colors[visit] == 0:
            colors[visit] = color
            dfs(visit, color)


for i in range(m):
    a, b = map(int, input().split())
    data[a - 1].append(b - 1)
    data[b - 1].append(a - 1)

for i in range(0, n):
    dfs(i, i + 1)

used = []

for color in colors:
    if color not in used:
        used.append(color)

print(len(used) - 1)