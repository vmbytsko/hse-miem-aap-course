import math

import numpy as np
from matplotlib import pyplot as plt

tend = int(input("Введите t: "))

t = np.arange(tend, dtype=float, step=0.01)
V = 5 * np.sin(2 * math.pi * t + 10)
tV = np.array([t, V]).transpose()

np.savetxt("data.txt", tV)

tV = np.loadtxt("data.txt")

plt.plot(tV[:, 0], tV[:, 1])

plt.xlabel("Ось X")
plt.ylabel("Ось Y")
plt.axline((0, 0), (1, 0), color='r')
plt.title("График V = 5sin(2pi*t+10)")
plt.grid()
plt.show()
