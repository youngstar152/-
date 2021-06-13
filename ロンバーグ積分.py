import math
from matplotlib import pyplot as plt

def f(x):
    return math.e**x
EPS = 10e-8 
N=1 
a=0.0
b=1.0
answer = math.e-1
h = 1.0-0.0 
T = [[0]*6 for x in range(0,6)]
T[0][0] = h * ( f(a) + f(b) )/2.0
xs = []
ys = []
n=0
while ( 1 ): 
    N = 2 * N 
    h = h / 2.0
    s = 0.0
    for i in range(1,N,2):
        s = s + f (a + i * h )
    T[n+1][0] = (T[n][0] / 2.0) + h * s 
    print("T[{}][{}]={},gosa={}".format(n,0,T[n][0],abs(answer-T[n][0])))
    if(N>16):
        break
    n+=1
    #xs.append(math.log10(N))
    #ys.append(math.log10(abs(answer-T_new)))
for k in range(1,5):
    for n in range(k,5):
        T[n][k]=(pow(4.0,k)*T[n][k-1]-T[n-1][k-1])/(pow(4.0,k)-1.0)
        print("T[{}][{}]={},gosa={}".format(n,k,T[n][k],abs(answer-T[n][k])))
#plt.xlabel("log10(N)")
#plt.ylabel("log10(E)")
#plt.plot(xs, ys,marker="o")
#plt.show()