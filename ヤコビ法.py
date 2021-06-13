import math
def yakobi(a,y):

    error = pow(10,-6)
    length = len(y)
    print(length)
    x = [0] * length
    x2 = [0] * length
    count = 0
    while True:
        sum=0
        for i in range(length):
            x2[i] = (y[i] - a[i][(i+1)%length]*x[(i+1)%length] - a[i][(i+2)%length]*x[(i+2)%length]) / a[i][i]
        for i in range(length):
            sum+=pow((x2[i] - x[i]),2)
        sum=math.sqrt(sum)      
        count += 1
        print("------" + str(count)+ "------")
        z=1.0
        for i in range(length):
            print(str(x2[i])+"//gosa:"+str(z-x2[i]))
            z+=1.0
        for i in range(length):
            x[i] = x2[i]
        if(sum<error):
            break  

a = [[7,-2,1],[-1,5,-2],[-2,-1,6]]
y = [6,3,14]
yakobi(a,y)