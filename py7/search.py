import os

def getFilesList(new_dir, toFind, mask):
    directories = os.listdir(new_dir)
    for dirictorie in directories:
        if os.path.isfile(dirictorie) and directories.endwith(mask):
            print(dirictorie)
        else:
            getFilesList(new_dir + '\\' + dirictorie, toFind, mask)

def goToNewDir(new_dir, toFind, mask):
    print(new_dir)
    directories = os.listdir(new_dir)
    print(directories)
    if toFind in directories:
        getFilesList(new_dir, toFind, mask)
    for dirictorie in directories:
        if os.path.isdir(dirictorie):
            goToNewDir(new_dir + '\\' + dirictorie, toFind, mask)

dir_now = 'C:\\'

toFind, mask = input().split()
goToNewDir(dir_now, toFind, mask)