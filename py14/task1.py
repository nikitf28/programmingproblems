stack1 = []
stack2 = []

n = int(input())

for i in range(n):
    cmd = input().split()
    if cmd[0] == "pushBack":
        prevMax = 0
        if len(stack1) > 0:
            prevMax = stack1[-1][1]
        stack1.append([int(cmd[1]), max(prevMax, int(cmd[1]))])
    elif cmd[0] == "max":
        max1, max2 = 0, 0
        if len(stack1) > 0:
            max1 = stack1[-1][1]
        if len(stack2) > 0:
            max2 = stack2[-1][1]
        print(max(max1, max2))
    elif cmd[0] == "popFront":
        if len(stack2) > 0:
            print(stack2[-1][0])
            stack2.pop()
        else:
            while len(stack1) > 0:
                stackData = stack1.pop()
                prewMax = 0
                if len(stack2) > 0:
                    prevMax = stack2[-1][1]
                stackData[1] = max(prevMax, stackData[0])
                stack2.append(stackData)
            print(stack2[-1][0])
            stack2.pop()