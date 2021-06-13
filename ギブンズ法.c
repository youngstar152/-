#include <stdio.h>
#include <math.h>
void givens ( int n , const double A[n][n], double Q[n][n], double R[n][n]) 
{
 int i , j , k;

 for (i = 0; i < n; ++ i ) {
    for (j = 0; j < n; ++ j ) {
        R[i ][ j] = A[i ][ j ];
    }
 }

 for (i = 0; i < n; ++ i ) {
    for (j = 0; j < n; ++ j ) {
        Q[i ][ j] = (i == j );
        }
 }

 for (i = 0; i < n; ++ i ) {
    for (j = i + 1; j < n ; ++ j) {
        double d = sqrt (R [i][i] * R [i][i] + R [j][i] * R [j][i]);
        double s = R[j ][ i ] / d;
        double c = R[i ][ i ] / d;
        for (k = 0; k < n; ++ k ) {
            double dik = R[ i ][ k ];
            double djk = R[ j ][ k ];
            R[i ][ k] = dik * c + djk * s;
            R[j ][ k] = - dik * s + djk * c ;
        }

        for (k = 0; k < n; ++ k ) {
            double dki = Q[ k ][ i ];
            double dkj = Q[ k ][ j ];
            Q[k ][ i] = dki * c + dkj * s;
            Q[k ][ j] = - dki * s + dkj * c ;
        }
    }
 }
 printf("Q----");
 printf("\n"); 
 for (i = 0; i < n; ++ i ) {
    for (k = 0; k < n; ++ k) {
        printf("%lf",Q[i][k]);
        printf(" ");
    }
    printf("\n");
 }

 printf("R----");
 printf("\n"); 
 for (i = 0; i < n; ++ i ) {
    for (k = 0; k < n; ++ k) {
        printf("%lf",R[i][k]);
        printf(" ");
    }
    printf("\n");
 }

}

void main(){
   int n;
   n=3;

   double A[3][3]={{3,1,2},
                   {1,5,6},
                   {4,9,5}};
   double Q[3][3]={{0,0,0},
                   {0,0,0},
                   {0,0,0}};
   double R[3][3]={{0,0,0},
                   {0,0,0},
                   {0,0,0}}; 
   givens(n,A,Q,R); 
}