import numpy as np
from scipy.linalg import lu

def gaussian_elimination(A, b):
    
    n = len(b)
    # 前進消去を行う
    for i in range(n):
        # pivot選択機能---------------------------------------------------------------------------------
        order = np.argmax(np.abs(A[i:, i]))  # pivot列i行目以上で最も絶対値の高い行を検索
        temp_A = A[i + order].copy()         # Aについて、最も絶対値の高い行成分を抽出し、別メモリで一時保持する
        temp_b = b[i + order].copy()         # bについて、最も絶対値の高い行成分を抽出し、別メモリで一時保持する
        A[i + order] = A[i]                  # Aについて、一時保持した行にi行目成分を置換する
        A[i] = temp_A                        # Aについて、保持しておいた行をi行目に置換する
        b[i + order] = b[i]                  # bについて、一時保持した行にi行目成分を置換する
        b[i] = temp_b                        # bについて、保持しておいた行をi行目に置換する
        # ----------------------------------------------------------------------------------------------
        pivot = A[i, i]                      # 対角成分をpivotに代入

        A[i] = A[i] / pivot                  # pivotで係数行列を割り、A[i,i]を1にする
        b[i] = b[i] / pivot                  # 定数ベクトルもpivotで割り同値変形する

        # i行目の定数倍をi+1行目以降から引くループ
        for j in range(i+1, n):
            p = A[j, i]                      # i+1行目以降i列の数値を格納
            A[j] -= p * A[i]                 # 係数行列のi+1行目からi行目の定数倍を引く
            b[j] -= p * b[i]                 # 定数ベクトルのi+1行目からi行目の定数倍を引く

    # 後退代入を行う
    x = np.zeros(n)                          # 解の入れ物を用意
    for i in reversed(range(n)):             # 最終行から後退処理する
        x[i] = b[i] / A[i, i]                # 解を求める
        for j in range(i):
            b[j] -= A[j, i] * x[i]           # 解が求まった列分bの値を上から更新する
    return x
#係数行列(n次正方行列であること)
N=10

A = np.zeros((N+1,N+1))
A[1][1]= -2
A[1][2]=1
for i in range(2,N):
    A[i][i]=-2
    A[i][i-1]=1
    A[i][i+1]=1
A[N][N]=-2
A[N][N-1]=1
        

A=np.delete(A,0,axis=0)
A=np.delete(A,0,axis=1)
print('A:{}'.format(A))    
P, L, U = lu(A,overwrite_a=True)
print('L:{}'.format(L))
print('U:{}'.format(U))    
#係数行列(n次正方行列であること)
#A = np.zeros(N,N+1) 

sum=0.05
#定数ベクトル
b = np.zeros(N+1) 
for i in range(1,N+1):
    b[i]=sum
    sum+=0.05
b=np.delete(b,0,axis=0)
print('b:{}'.format(b))
#print(':{}'.format(b))  
#b = np.array([1.0/answer[1]+1.0/answer[2], 1.0/answer[2]+1.0/answer[3]],dtype=float)
# ガウスの消去法関数を実行して解を得る
c = gaussian_elimination(L, b)
x = gaussian_elimination(U, c)
np.set_printoptions(precision=7, floatmode='fixed')
print(N,end='')
print(':answer:{}'.format(x)) 
