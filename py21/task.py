n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]

minPointWeight = 999999
minPointA = 0
minPointB = 0

for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if data[i][j] < minPointWeight:
            minPointWeight = data[i][j]
            minPointA = i
            minPointB = j

pointsList = [minPointA, minPointB]
ribs = [(minPointA, minPointB)]

while len(pointsList) < n:
    minPointWeight = 999999
    minPointB = 0
    minPointA = 0
    for point in pointsList:
        #print(pointsList)
        for j in range(n):
            if data[point][j] < minPointWeight and j not in pointsList and data[point][j] != 0:
                minPointWeight = data[point][j]
                minPointB = j
                minPointA = point
                #print(minPointWeight)
    pointsList.append(minPointB)
    ribs.append((minPointA, minPointB))

#print(ribs)
ribs.sort()

for rib in ribs:
    print(str(rib[0] + 1) + " - " + str(rib[1] + 1))
