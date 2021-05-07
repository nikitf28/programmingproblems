size = 0
maxSize = 1025
priorityQueue = [None for i in range(maxSize)]

def parent(i):
    return i // 2

def childL(i):
    return i * 2

def childR(i):
    return i * 2 + 1

def shiftUp(i):
    global priorityQueue
    while i > 1 and priorityQueue[parent(i)] < priorityQueue[i]:
        temp = priorityQueue[i]
        priorityQueue[i] = priorityQueue[parent(i)]
        priorityQueue[parent(i)] = temp
        i = parent(i)
        
def shiftDown(i):
    global priorityQueue
    global size
    maxIndex = i
    l = childL(i)
    if l <= size and priorityQueue[l] > priorityQueue[maxIndex]:
        maxIndex = l
    r = childR(i)
    if r <= size and priorityQueue[r] > priorityQueue[maxIndex]:
        maxIndex = r
    if i != maxIndex:
        temp = priorityQueue[i]
        priorityQueue[i] = priorityQueue[maxIndex]
        priorityQueue[maxIndex] = temp
        shiftDown(maxIndex)

def insertL(p):
    global size
    global maxSize
    global priorityQueue
    if size == maxSize:
        print("Too big!!!")
        return "Error"
    size += 1
    priorityQueue[size] = p
    shiftUp(size)

def extractMax():
    global priorityQueue
    global size
    result = priorityQueue[0]
    priorityQueue[0] = priorityQueue[size]
    size -= 1
    shiftDown(1)
    return result

def removeL(m):
    global priorityQueue
    priorityQueue[m] = 999999999
    shiftUp(m)
    extractMax()

def getMax():
    global priorityQueue
    return priorityQueue[1]

def changePriority(m, p):
    global priorityQueue
    pass

n = int(input())

def validateStack():
    


data = list(map(int, input().split()))
for el in data:
    insertL(el)
print(priorityQueue)
