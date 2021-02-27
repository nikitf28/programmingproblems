def toFixed(numObj, digits=2):
    return f"{numObj:.{digits}f}"

n = int(input())

companyData = {}

for i in range(n):
    info = input().split()
    companyData[info[0]] = float(info[2]) / float(info[1]) * 100

print('STATISTICS: ')
for company in companyData.keys():
    print(company + ": " + str(toFixed(companyData[company])) + "%")

print()
print("FAILED: ")
for company in companyData.keys():
    if companyData[company] < 90:
        print(company + ": " + str(toFixed(companyData[company])) + "%")

"""
Input sample:
=============
7
Rosneft 100 89
Gazprom 100 150
Sberbank 78 90
Tinkoff 500 900
Roscosmos 500 300
Yandex 400 450
MailRu 350 300
==============

Output sample:
==============
STATISTICS: 
Rosneft: 89.00%
Gazprom: 150.00%
Sberbank: 115.38%
Tinkoff: 180.00%
Roscosmos: 60.00%
Yandex: 112.50%
MailRu: 85.71%

FAILED: 
Rosneft: 89.00%
Roscosmos: 60.00%
MailRu: 85.71%
=========
"""
