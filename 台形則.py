import math
from matplotlib import pyplot as plt

def f(x):
    return 1/math.sqrt(3.0-2.0*x*x)
    EPS = 10e-8 
N=1
a=0.0
b=1.0
answer = math.e-1
h = 1.0-0.0 
T = h * ( f(a) + f(b) )/2.0
s = 0.0
xs = []
ys = []
for i in range(1,N,2):
    print(a + i * h)
    s = s + f (a + i * h )
    print(s)
    
T_new = T / 2.0 + h * s
print("N={}::atai={}::gosa={}".format(N,T_new,abs(answer-T_new)))
xs.append(math.log10(N))
ys.append(math.log10(abs(answer-T_new)))
for z in range(5): 
    N = 2 * N 
    h = h / 2.0
    s = 0.0
    for i in range(1,N,2):
        s = s + f (a + i * h )
    
    T_new = T / 2.0 + h * s
    if N==2:
        T = T_new
        continue
    print("N={}::atai={}::gosa={}".format(N,T_new,abs(answer-T_new)))
    xs.append(math.log10(N))
    ys.append(math.log10(abs(answer-T_new)))
    T = T_new
    if(N>4096):
        break
plt.xlabel("log10(N)")
plt.ylabel("log10(E)")
plt.plot(xs, ys,marker="o")
plt.show()
    
 