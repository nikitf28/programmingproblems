params = int(input('Insert amount of parametres: '))

expNum = int(input('Insert amount of rows in experemental group: '))
experementalData = []

for i in range(expNum):
    expRow = list(map(int,input().split()))
    while len(expRow) != params:
        print('Wrong row, skipping... Insert a new one.')
        expRow = map(int, input().split())
    experementalData.append(expRow)

controlNum = int(input('Insert amount of rows in control group: '))
controlData = []

for i in range(controlNum):
    controlRow = list(map(int,input().split()))
    while len(controlRow) != params:
        print('Wrong row, skipping... Insert a new one.')
        controlRow = map(int, input().split())
    controlData.append(controlRow)

for i in range(params):
    rangedArray = []
    for j in range(expNum):
        experement = {'value': 0, 'type': 'exp', 'rang': -1}
        experement['value'] = experementalData[j][i]
        rangedArray.append(experement)
    for j in range(controlNum):
        experement = {'value': 0, 'type': 'contr', 'rang': -1}
        experement['value'] = controlData[j][i]
        rangedArray.append(experement)

    for j in range(len(rangedArray)):
        for o in range(len(rangedArray)):
            if rangedArray[j]['value'] < rangedArray[o]['value']:
                t = rangedArray[j]
                rangedArray[j] = rangedArray[o]
                rangedArray[o] = t

    for j in range(len(rangedArray)):
        if j != len(rangedArray) - 1:
            if rangedArray[j]['value'] != rangedArray[j+1]['value']:
                rangedArray[j]['rang'] = j + 1
            else:
                sameNum = rangedArray[j]['value']
                l = j + 1
                nums = 1
                sums = j
                while l < len(rangedArray) and rangedArray[l]['value'] == sameNum:
                    sums += l
                    nums += 1
                    l += 1
                    if l == len(rangedArray):
                        break
                print(sums, nums)
                for o in range(j, j + nums):
                    rangedArray[o]['rang'] = sums / nums

        else:
            rangedArray[j]['rang'] = j + 1

    N = expNum + controlNum
    nx = 0
    T1 = 0
    T2 = 0
    Tx = 0

    for j in range(len(rangedArray)):
        if rangedArray[j]['type'] == 'contr':
            T2 += rangedArray[j]['value']
        else:
            T1 += rangedArray[j]['value']

    print(rangedArray)

    if T1 > T2:
        Tx = T1
        nx = expNum
    else:
        Tx = T2
        nx = controlNum

    U = expNum * controlNum + nx*(nx-1)/2 - Tx

    print('Param #%s result: %s' % (i+1, U))