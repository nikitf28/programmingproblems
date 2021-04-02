n = int(input())

stack = []

for i in range(n):
    input_data = input().split()
    if input_data[0] == 'push':
        prev_max = 0
        if len(stack) > 0:
            prev_max = stack[-1][1]
        tut = (int(input_data[1]), max(int(input_data[1]), prev_max))
        stack.append(tut)
    elif input_data[0] == 'pop':
        if len(stack) > 0:
            stack.pop()
        else:
            print('Stack length is already 0!')
    elif input_data[0] == 'max':
        if len(stack) > 0:
            print(stack[-1][1])
        else:
            print('Stack length is 0!')