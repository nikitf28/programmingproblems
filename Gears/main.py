import matplotlib.pyplot as plt
import numpy as np

data = []

with open('output.txt', 'r') as f:
    fl = False
    for line in f:
        if not fl:
            fl = True
            continue
        d = []
        for s in line:
            if s.isnumeric():
                d.append(int(s))
        data.append(d)

plt.imshow(data)
plt.show()