#include<stdio.h>
#include<math.h>

double f(double x){
    return exp(-x*x)-sin(x);
}

double f_bibun(double x){
    return -2*x*exp(-x*x)-cos(x);
}

double nibun(double a,double b,double d){
    double c;
    int tmp;
    while (1){
        c=(a+b)/2;
        tmp +=1;
        if(((fabs(a-b))/2)<d){
            printf("%d",tmp);
            return c;
        }
        if(f(c)>0){
            b=c;
        }
        if(f(c)<0){
            a=c;
        }   
        if(f(c)==0){
            printf("%d",tmp);
            return c;
        }    
    }
}

double newton(double a,double d){
    double c;
    int tmp;
    while(1){
        c=a-f(a)/f_bibun(a);
        tmp +=1;
        if(fabs(c-a)<d*fabs(c)){
            printf("%d",tmp);
            return c;
        }
        a=c;
    }

}

int main(){
    printf("回:nibun:x2=%.13lf\n",nibun(3,4,pow(10,-15)));
    printf("回:nibun:x3=%.13lf\n",nibun(7,6,pow(10,-15)));
    printf("回:newton:x2=%.13lf\n",newton(3,pow(10,-15)));
    printf("回:newton:x3=%.13lf\n",newton(7,pow(10,-15)));
    return 0;
}