n = int(input())

output = []

for i in range(n):
    nums = list(map(int, input().split()))
    for j in range(i, n):
        if nums[j] == 1:
            output.append(str(i + 1) + " " + str(j + 1))

for line in output:
    print(line)