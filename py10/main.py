import time
import sys

for i in range(101):
    sys.stdout.write('%d\r' % i)
    time.sleep(1)