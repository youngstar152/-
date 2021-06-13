import math
def yakobi(a,y):

    error = pow(10,-6)
    length = len(y)
    x = [0] * length
    x2 = [0] * length
    count = 0
    while True:
        sum=0
        x2[0] = (y[0] - a[0][1]*x[1] - a[0][2]*x[2]) / a[0][0]
        x2[1] = (y[1] - a[1][2]*x2[2] - a[1][0]*x[0]) / a[1][1]
        x2[2] = (y[2] - a[2][0]*x2[0] - a[2][1]*x2[1]) / a[2][2]
        for i in range(length):
            sum+=pow((x2[i] - x[i]),2)
        sum=math.sqrt(sum)     
        count += 1
        print("------" + str(count)+ "------")
        z=1.0
        for i in range(length):
            print(str(x2[i])+"//gosa:"+str(z-x2[i]))
            z+=1.0
        print("total-gosa:"+str(sum))
        if(sum<error):
            break
        for i in range(length):
            x[i] = x2[i]   

a = [[7,-2,1],[-1,5,-2],[-2,-1,6]]
y = [6,3,14]
yakobi(a,y)