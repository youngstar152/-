#include <stdio.h>
#include <math.h>

void householder ( int n , const double A[n ][ n], double Q[n ][ n], double R[n ][ n ]) {
 int i , j , k;
 double y[n ];

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

 for (i = 0; i < n - 1; ++ i) {
    double v[n ];
    for (j = 0; j < n; ++ j )v[j ] = 0.0;
    double sigma = 0.0;
    for (j = i; j < n; ++ j ) {
        sigma += R[j ][ i] * R[j ][ i ];
        v[j] = R[j ][ i ];
    }
    sigma = sqrt ( sigma );
    if (v[i] >= 0.0) {
        v[i] -= sigma ;
    } else {
        v[i] += sigma ;
 }

    double alpha = 0.0;
    for (j = i; j < n; ++ j ) alpha += v[ j] * v [j ];
    alpha = 2.0 / alpha ;


    for (j = i; j < n; ++ j ) {
        y[j] = 0.0;
        for (k = i ; k < n; ++ k ) y [j] += v[k ] * R[ k ][ j ];
        y[j] *= alpha ;
    }

    for (j = i; j < n; ++ j ) {
        for (k = i ; k < n; ++ k ) {
            R[j ][ k] -= v[j ] * y[ k ];
    }
 }

    for (j = 0; j < n; ++ j ) {
        y[j] = 0.0;
        for (k = 0; k < n; ++ k ) y [j] += Q[j ][ k] * v[ k ];
            y[j] = alpha * y [j ];
    }
    for (j = 0; j < n; ++ j ) {
        for (k = 0; k < n; ++ k ) {
            Q[j ][ k] -= y[j ] * v[ k ];
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
   householder(n,A,Q,R); 
}
