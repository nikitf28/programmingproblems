def validateLength(data):
    i = 0.5
    while i <= len(data):
        i *= 2
        if i == len(data) + 1:
            return True
    return False

def validateTree(data):
    newData = [0] + data
    for i in range(1, len(newData)):
        if i*2 + 1 < len(newData):
            if newData[i] < newData[i*2] or newData[i] < newData[i*2+1]:
                #print(newData[i], newData[i*2],  newData[i*2+1])
                return False
    return True

data = list(map(int, input().split()))

#print(validateLength(data))
#print(validateTree(data))

if validateLength(data) and validateTree(data):
    print("Normal structure")
else:
    print("Incorrect structure")
