eq = input()

num1, num2 = 0, 0

toDo = eq[1]

s1 = eq[0]
s2 = eq[2]
s3 = eq[4]

if s1 == 'x':
    num1 = int(s2)
    num2 = int(s3)

if s2 == 'x':
    num1 = int(s1)
    num2 = int(s3)

if s3 == 'x':
    num1 = int(s1)
    num2 = int(s2)

if toDo == '+':
    if s1 == 'x' or s2 == 'x':
        print(num2-num1)
    if s3 == 'x':
        print(num1 + num2)

if toDo == '-':
    if s1 == 'x':
        print(num1 + num2)
    if s2 == 'x' or s3 == 'x':
        print(num1 - num2)