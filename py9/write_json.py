import json

users = []

i = 1

print("To finisg write \"end\"")

while True:
    print("User #" + str(i))
    name = input('Name: ')
    if name == 'end':
        break
    last_online = input('Last online: ')
    if last_online == 'end':
        break
    continious = input('Was online for: (seconds) ')
    if continious == 'end':
        break
    user = {'name': name, 'last_online': last_online, 'continious': int(continious)}
    users.append(user)

    i+=1

print('Saving data...')

with open("users_export.json", "w") as write_file:
    json.dump(users, write_file)