words = {}

n = int(input())

for i in range(n):
    row = input().split()
    for word in row:
        if word in words:
            words[word] += 1
        else:
            words[word] = 1

niceWords = {}

for key in words.keys():
    if words[key] in niceWords:
        niceWords[words[key]].append(key)
    else:
        niceWords[words[key]] = [key]

list_keys = list(niceWords.keys())
list_keys.sort()

for i in range(len(list_keys) - 1, -1, -1):
    outputList = niceWords[list_keys[i]]
    outputList.sort()
    print(str(list_keys[i]))
    print("==========")
    for word in outputList:
        print(word)
    print()
    
"""
Sample input:
_____________
9
hi
hi
what is your name
my name is bond
james bond
my name is damme
van damme
claude van damme
jean claude van damme
______________


Sample output:
______________
4
==========
damme

3
==========
is
name
van

2
==========
bond
claude
hi
my

1
==========
james
jean
what
your
______________
"""