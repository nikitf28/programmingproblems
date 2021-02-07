n = int(input())


arr = []
arr1 = []
for i in range(n):
    arr1.append(0)
            
for i in range(n):
    arr.append(arr1.copy())


d = "right"
x, y = 0, 0

for i in range(n*n):
    #print(str(x) + ' ' + str(y) + ' ' + d)
    if d == "right":
        arr[y][x] = i + 1
        x += 1
        if x == n - 1:
            d = "down"
        elif arr[y][x+1] != 0:
            d = "down"
        continue
    elif d == "down":
        arr[y][x] = i + 1
        y += 1
        if y == n - 1:
            d = 'left'
        elif arr[y+1][x] != 0:
            print(arr[y+1][x])
            d = 'left'
        continue
    elif d == 'left':
        arr[y][x] = i + 1
        x -= 1
        if x == 0:
            d = "up"
        elif arr[y][x-1] != 0:
              d = "up"
        continue
    elif d == "up":
        arr[y][x] = i + 1
        y -= 1
        if y == 0:
            d = 'right'
        elif arr[y-1][x] != 0:
            d = 'right'
        continue


for i in arr:
    for j in i:
        print(j, end=" ")
    print()
