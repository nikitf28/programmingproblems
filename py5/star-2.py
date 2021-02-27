words = []
superSuffix = []

n = int(input())
for i in range(n):
    words.append(input())

m = int(input())
for i in range(m):
    superSuffix.append(input())

for suffix in superSuffix:
    ans = 0
    lnth = len(suffix)
    for word in words:
        if len(word) >= lnth:
            if word[:lnth] == suffix and word[-1*lnth:] == suffix:
                ans += 1
    print(ans)