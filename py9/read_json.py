import json

with open('users.json', 'r') as read_file:
    data = json.load(read_file)

for user in data['users']:
    print('=========================================')
    print('Login:', user['login'])
    print('Last login:', user['last_login'])
    print('Was online for: ', user['continious'], 'seconds')
    print('=========================================')
    print('')
