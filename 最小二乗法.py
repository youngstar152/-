import math
from matplotlib import pyplot as plt
import numpy as np


def lt(xs1, xs2):
    return [xs1[i] * xs2[i] for i in range(len(xs1))]

f = open('halebopp.dat', 'r')
lines = f.readlines()
xs = []
ys = []
for line in lines:
    data = [e for e in line.replace("\n", "").split(" ") if e != ""]
    r = float(data[3])
    delta = float(data[4])
    m1 = float(data[5])
    xs.append(math.log10(r))
    ys.append(m1 - 5 * math.log10(delta))
f.close()

N = len(xs)
xy = lt(xs, ys)
xx = lt(xs, xs)
bunbo = N * sum(xx) - sum(xs) * sum(xs)
K = (N * sum(xy) - sum(xs) * sum(ys)) / bunbo
H = (sum(xx) * sum(ys) - sum(xs) * sum(xy)) / bunbo
print(K)
print(H)

hensu = np.linspace(-0.2, 1.0)

plt.scatter(xs, ys)
plt.plot(hensu, K * hensu + H)
plt.show()
