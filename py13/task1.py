input_data = input()

stack = []

for i in range(len(input_data)):
    s = input_data[i]
    if s == '(' or s == '{' or s == '[':
        stack.append((s, i))
    elif s ==')' or s == '}' or s == ']':
        last = ""
        if len(stack) > 0:
            last = stack[-1][0]
        else:
            print(i + 1)
            break
        if last == '(' and s == ')' or last == '{' and s == '}' or last == '[' and s == ']':
            stack.pop()
        else:
            print(i + 1)
            break

    if i == len(input_data) - 1:
        if len(stack) == 0:
            print("Success")
        else:
            print(stack[0][1] + 1)