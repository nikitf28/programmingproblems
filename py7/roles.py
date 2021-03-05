lines = []
scenario = {}

with open("sample2.txt", encoding='utf-8') as file:
    lines = [row.strip() for row in file]

mode = 0
counter = 0
name = ''

for line in lines:
    print(line)
    if line == '﻿roles:':
        mode = 1
        continue
    if line == 'textLines:':
        mode = 2
        continue
    if mode == 1:
        scenario[line] = []
    if mode == 2:
        counter += 1
        newLine = str(counter) + ')'
        m = 0
        newName = ''
        for l in line:
            if l == ':':
                if newName in scenario.keys():
                    name = newName
                    m = 1
                continue
            if m == 0:
                newName += l
            if m == 1:
                newLine += l
        if m == 0:
                counter -= 1
                scenario[name].append(newName)
                continue
        scenario[name].append(newLine)

for name in scenario.keys():
    print(name + ':')
    for line in scenario[name]:
        print(line)
    print()