#include <stdio.h>
#include <math.h>

void gram ( int n , const double A[n ][ n], double Q[n ][ n], double R[n ][ n ]) {
 int i , j , k;

 for (i = 0; i < n; ++ i ) {
    for (j = 0; j < n; ++ j ) {Q [j ][ i] = A [j ][ i ];}
    for (j = 0; j < i; ++ j ) {
        double dcoef = 0.0;
        for (k = 0; k < n; ++ k ) dcoef += A[ k ][ i ] * Q [k ][ j ];
        for (k = 0; k < n; ++ k ) Q [k ][ i] -= dcoef * Q [k ][ j ];
 }

        double dtemp1 = 0.0;
        for (j = 0; j < n; ++ j ) dtemp1 += Q [j ][ i] * Q [j ][ i ];
        dtemp1 = 1.0 / sqrt ( dtemp1 );
        for (j = 0; j < n; ++ j ) Q [j ][ i] = Q [j ][ i] * dtemp1 ;
        }

 for (i = 0; i < n; ++ i ) {
    for (j = 0; j < n; ++ j ) {
         R[i ][ j] = 0.0;
    }
 }
 for (i = 0; i < n; ++ i ) {
    for (j = 0; j <= i; ++ j) {
        R[j ][ i] = 0.0;
        for (k = 0; k < n; ++ k ) R [j ][ i] += A[k ][ i] * Q[k ][ j ];
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
   gram(n,A,Q,R); 
}
