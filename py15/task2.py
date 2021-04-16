def addNewPoint(tree, point):
    i = 1
    while True:
        while i > len(tree) - 1:
            tree.append(None)
        if tree[i] == None:
            tree[i] = point
            break
        if tree[i] > point:
            i *= 2
        else:
            i = i * 2 + 1
    #print(tree)


def findPoint(tree, point):
    i = 1
    deep = 0
    while i <= len(tree) - 1:
        if tree[i] == None:
            break
        if tree[i] == point:
            return deep
        if tree[i] > point:
            i *= 2
        else:
            i = i * 2 + 1
        deep += 1
    return -1

def delElement(tree, point):
    i = 1
    while i <= len(tree) - 1:
        if tree[i] == None:
            return -1
        if tree[i] == point:
            break
        if tree[i] > point:
            i *= 2
        else:
            i = i * 2 + 1
    if i * 2 > len(tree) - 1:
        tree[i] = None
        return 1
    elif tree[i*2] != None:
        j = i
        while j * 2 <= len(tree) - 1 and tree[j * 2] != None:
            j *= 2
        tree[i] = tree[j]
        tree[j] = None
    elif tree[i*2 + 1] != None:
        j = i
        while j * 2 + 1 <= len(tree) - 1 and tree[j * 2 + 1] != None:
            j = j * 2 + 1
        tree[i] = tree[j]
        tree[j] = None
    else:
        tree[i] = None


tree = []
input_data = list(map(int, input().split()))
n = int(input())

for el in input_data:
    addNewPoint(tree, el)

print(findPoint(tree, n))

print(tree)

delElement(tree, int(input()))

print(tree)