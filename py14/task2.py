def pushBack(data, stack1):
    prevMax = 0
    if len(stack1) > 0:
        prevMax = stack1[-1][1]
    stack1.append([data, max(prevMax, data)])


def lineMax(stack1, stack2):
    max1, max2 = 0, 0
    if len(stack1) > 0:
        max1 = stack1[-1][1]
    if len(stack2) > 0:
        max2 = stack2[-1][1]
    print(max(max1, max2), end=" ")


def popFront(stack1, stack2):
    if len(stack2) > 0:
        stack2.pop()
        #print(stack2[-1][0])
    else:
        while len(stack1) > 0:
            stackData = stack1.pop()
            prevMax = 0
            if len(stack2) > 0:
                prevMax = stack2[-1][1]
            stackData[1] = max(prevMax, stackData[0])
            stack2.append(stackData)
        #print(stack2[-1][0])
        stack2.pop()


stack1 = []
stack2 = []

n = int(input())

arr = list(map(int, input().split()))
m = int(input())

for s in arr:
    pushBack(int(s), stack1)
    #print(stack1)
    #print(stack2)
    if len(stack1) + len(stack2) < m:
        continue
    lineMax(stack1, stack2)
    #print(lineMax(stack1, stack2), end=" ")
    popFront(stack1, stack2)