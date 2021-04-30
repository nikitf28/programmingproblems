n = int(input())
output = []

for i in range(n):
    data = list(map(int, input().split()))
    sm = 0
    for el in data:
        sm += el
    output.append(sm)

for el in output:
    print(el, end=" ")
