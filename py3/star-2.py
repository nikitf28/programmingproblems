def dfs(point, marker):
    if len(graph[point]) > 0:
        if graph[point][-1] < 0:
            return -1
    graph[point].append(marker*(-1))
    for p in graph[point]:
        if p > 0:
            dfs(p, marker)
    return 0

N, M = map(int, input().split())

graph = [[] for i in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

marker = 1

for i in range(1, N + 1):
    if dfs(i, marker) == 0:
        marker += 1

for i in range(1, N + 1):
    print(graph[i][-1]*(-1), end=' ')
