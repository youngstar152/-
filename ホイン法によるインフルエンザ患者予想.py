import matplotlib.pyplot as plt

def divf(t,S,I,R):
    return -0.0015*S*I

def divf2(t,S,I,R):
    return 0.0015*S*I-0.9*I

def divf3(t,S,I,R):
    return 0.9*I

# ホイン法
def imp_euler(t, S, I, R, h, b):
  t_ap = [t]
  S_ap = [S]
  I_ap = [I]
  R_ap = [R]
  total=[S+I+R]
  while t <= b:

    S_1 = S + h * divf(t,S,I,R)
    I_1 = I + h * divf2(t,S,I,R)
    R_1 = R + h * divf3(t,S,I,R)

    S += (divf(t,S,I,R) + divf((t + h), S_1,I_1, R_1)) * h / 2.0
    I += (divf2(t,S,I,R) + divf2((t + h), S_1,I_1, R_1)) * h / 2.0
    R += (divf3(t,S,I,R) + divf3((t + h), S_1,I_1, R_1)) * h / 2.0

    t += h
    total1=S+I+R

    S_ap.append(S)
    I_ap.append(I)
    R_ap.append(R)
    t_ap.append(t)
    total.append(total1)
  return t_ap, S_ap, I_ap, R_ap,total

#何週目まで計算するか
b=30
# オイラー法のグラフ
t_a , S_a , I_a, R_a ,total_a= imp_euler(0.0, 1000.0, 1.0, 0.0, 0.01, b)
#ax.scatter(x_a, y_a, c='purple', label='Euler')


# グラフタイトルなどの表示
plt.xlabel("t")
plt.ylabel("S")
plt.yticks([i for i in range(-50, 1100, 50)] )
plt.plot(t_a, S_a, marker="o",color="red")
plt.plot(t_a, I_a, marker="o",color="blue")
plt.plot(t_a, R_a, marker="o",color="green")
plt.plot(t_a, total_a, marker="o",color="black")
plt.show()
#ax.legend(loc='best')
#ax.grid(True) 