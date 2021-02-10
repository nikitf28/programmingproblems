r, g, b, f = 0, 0, 0, 0

n, m = input().split()
n, m = int(n), int(m)

for i in range(1, n+1):
    for j in range(1, m+1):
        p = 'f'
        if i*j % 2 == 0:
            p = 'r'
        if i*j % 3 == 0:
            p = 'g'
        if i*j % 5 == 0:
            p = 'b'
        
        if p == 'f':
            f += 1
        elif p == 'r':
            r += 1
        elif p == 'g':
            g += 1
        elif p == 'b':
            b += 1

print('RED :', r)
print('GREEN :', g)
print('BLUE :', b)
print('BLACK :', f)

