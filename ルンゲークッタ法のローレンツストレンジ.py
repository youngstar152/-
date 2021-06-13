import matplotlib.pyplot as plt

def divf(t,x,y,z):
    return -10.0*x+10.0*y

def divf2(t,x,y,z):
    return -x*z+28.0*x-y

def divf3(t,x,y,z):
    return x*y-(8.0/3.0)*z

# RK4法
def rk4(t, x, y, z, h, b):
  x_ap = [x]
  y_ap = [y]
  z_ap = [z]
  t_ap = [t]

  while t <= b:

    k1_x = divf(t,x,y,z)
    k1_y = divf2(t,x,y,z)
    k1_z = divf3(t,x,y,z)

    x_1 = x + k1_x * h / 2.0
    y_1 = y + k1_y * h / 2.0
    z_1 = z + k1_z * h / 2.0

    k2_x = divf((t + h/2.0), x_1, y_1, z_1)
    k2_y = divf2((t + h/2.0), x_1, y_1, z_1)
    k2_z = divf3((t + h/2.0), x_1, y_1, z_1)

    x_2 = x + k2_x * h / 2.0
    y_2 = y + k2_y * h / 2.0
    z_2 = z + k2_z * h / 2.0

    k3_x = divf((t + h/2.0), x_2, y_2, z_2)
    k3_y = divf2((t + h/2.0), x_2, y_2, z_2)
    k3_z = divf3((t + h/2.0), x_2, y_2, z_2)

    x_3 = x + k3_x * h 
    y_3 = y + k3_y * h 
    z_3 = z + k3_z * h 

    k4_x = divf((t + h), x_3, y_3, z_3)
    k4_y = divf2((t + h), x_3, y_3, z_3)
    k4_z = divf3((t + h), x_3, y_3, z_3)

    x += (k1_x + 2.0 * k2_x + 2.0 * k3_x + k4_x) * h / 6.0
    y += (k1_y + 2.0 * k2_y + 2.0 * k3_y + k4_y) * h / 6.0
    z += (k1_z + 2.0 * k2_z + 2.0 * k3_z + k4_z) * h / 6.0
    t += h

    x_ap.append(x)
    y_ap.append(y)
    z_ap.append(z)
    t_ap.append(t)

  return t_ap, x_ap, y_ap, z_ap

b=100
# ルンゲークッタ法のグラフ
t_a , x_a , y_a, z_a = rk4(0.0, 1.0, 1.0, 1.0, 0.001, b)
with open('suuti7-2.dat', 'w') as f:
    for i in range(100000):
        f.write('{} {} {}'.format(x_a[i],y_a[i],z_a[i]))
        f.write('\n')
f.close()