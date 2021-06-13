import math
from matplotlib import pyplot as plt

def f(x):
    return 1/math.sqrt(3.0-2.0*x*x)
EPS = 10e-8 
N=2
a=0.0
b=1.0
answer = math.e-1
h = (1.0-0.0)/2.0 
T = (h * ( f(a) + 2.0*f((a+b)/2.0) +f(b)))/2.0
S = (h * ( f(a) + 4.0*f((a+b)/2.0) +f(b)))/3.0
#s = 0.0
xs = []
ys = []
#print("N={}::atai={}::gosa={}".format(N,S,abs(answer-S)))
xs.append(math.log10(N))
ys.append(math.log10(abs(answer-S)))

for z in range(4): 
    N = 2 * N 
    h = h / 2.0
    s = 0.0
    for i in range(1,N,2):
        s = s + f (a + i * h )
    
    T_new = T / 2.0 + h * s
    S_new= (4.0*T_new - T)/3.0
    print("N={}::atai={}::gosa={}".format(N,S_new,abs(answer-S_new)))
    xs.append(math.log10(N))
    ys.append(math.log10(abs(answer-S_new)))
    T = T_new
    S = S_new
    if(N>4096):
        break
plt.xlabel("log10(N)")
plt.ylabel("log10(E)")
plt.plot(xs, ys,marker="o")
plt.show()