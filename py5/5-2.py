words = {}

n, m = map(int, input().split())
speech = input()

for i in range(n-m+1):
    word = speech[i:i+m]
    words[word] = 1

print(len(words))