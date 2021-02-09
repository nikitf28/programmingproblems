for num in range (1, 32001):
    ch = num
    summ = 0
    digits = []
    while ch > 0:
        digit = ch % 10
        digits.append(digit)
        ch = ch // 10
    for digit in digits:
        summ += digit**len(digits)
    if summ == num:
        print(num)
