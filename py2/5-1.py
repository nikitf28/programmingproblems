n = int(input())

summ = 0

for i in range(n):
    row = input().split()
    for num in row:
        summ += int(num)

print(summ//2)
