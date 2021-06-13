#include<stdio.h>
#include<math.h>

double f(double x){
    return 1/(1+25*pow(x,2));
}

double l_j (double x, int j, int N, double *x_j)
{
 double x_u, x_l;
 x_u = 1.0;
 x_l = 1.0;
 for (int i=0; i<N; i++) {
    if (j != i) {
        x_u = x_u * (x - x_j[i]);
        x_l = x_l * (x_j[j] - x_j[i]);
        }
    }
 return (x_u / x_l);
}
int main(){
    FILE *file;
    file = fopen("suuti3-1-2.dat","w");
    int N = 11;
    double x_j[11];
    double y_j[11];
    //サンプリング点の設定
    for(int i=0; i<N; i++ ){   
        x_j[i] = -1.0 + i*(2.0/(N-1.0));
        y_j[i] = f(x_j[i]);
    } 
    //補間計算
    for (int i=0; i<10000; i++ ){
        double x;
        double y;
        x = -1.0 + (2 / 10000.00) * (double)i;
        y = 0.0;
        for(int j=0; j<N; j++) {
            y = y + y_j[j] * l_j(x, j, N, x_j);
        }
        fprintf(file,"%lf %lf\n",x,y); 
    }
    fclose(file);
}