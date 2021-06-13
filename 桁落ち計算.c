#include <stdio.h>
#include <math.h>

double keisan1(double a,double b,double c){
    return ((-b+sqrt(b*b-4*a*c))/2*a);
}

double keisan2(double a,double b,double c){
    return ((-b-sqrt(b*b-4*a*c))/2*a);
}

double kaihi(double a,double b, double c){
    double x = keisan1(a,b,c);
    return c/(a*x);
}
int main (void)
{
    printf("x1=%.16lf\n",keisan1(1.0,-50000.0001,5));
    printf("x2=%.16lf\n",keisan2(1.0,-50000.0001,5));
    printf("桁落ち回避\n");
    printf("x1=%.16lf\n",keisan1(1.0,-50000.0001,5));
    printf("x2=%.16lf\n",kaihi(1.0,-50000.0001,5));
}