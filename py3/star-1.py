T = int(input())

for i in range(T):
    A, B, C = list(map(int, input().split()))
    mx, my = 0, 0
    for x in range(0, C+1):
        y = (C - A * x)/B
        if y < 0:
            break
        if y == int(y) and mx + my < x + y:
            mx, my = x, int(y)
    if mx == 0 and my == 0:
        print(-1)
    else:
        print(mx+my)
            
