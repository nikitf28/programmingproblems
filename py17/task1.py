table = []

def hashT(s, m):
    summ = 0
    for i in range(len(s)):
        summ += ord(s[i])*262**i
    result = (summ % 1000000007)%m
    return result


def addT(value, m):
    global table
    table = [value, hashT(value, m)] + table
    
def delT(value, m):
    hashed = hasgT(value, m)
    for i in range(len(table)):
        if 
