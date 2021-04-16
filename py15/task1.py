def addNewPoint(tree, point):
    i = 1
    while True:
        while i > len(tree) - 1:
            tree.append("null")
        if tree[i] == "null":
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
        if tree[i] == "null":
            break
        if tree[i] == point:
            return deep
        if tree[i] > point:
            i *= 2
        else:
            i = i * 2 + 1
        deep += 1
    return -1


tree = []
input_data = list(map(int, input().split()))
n = int(input())

for el in input_data:
    addNewPoint(tree, el)

print(findPoint(tree, n))