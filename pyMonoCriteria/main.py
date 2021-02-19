params = int(input('Insert amount of parametras'))

expNum = int(print('Insert amount of rows in experemental group'))
experementalData = []

for i in range(expNum):
    expRow = map(int,input().split())
    while len(expRow) != expNum:
        print('Wrong row, skipping... Insert a new one.')
        expRow = map(int, input().split())

controlNum = int(print('Insert amount of rows in control group'))
controlData = []

for i in range(controlNum):
    controlRow = map(int,input().split())
    while len(controlRow) != controlNum:
        print('Wrong row, skipping... Insert a new one.')
        controlRow = map(int, input().split())

