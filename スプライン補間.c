#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//   マクロ定義
#define  NP      11      //  節点の数
#define  NINT    2000     //  全区間の等分数( 全区間を NINT 等分した点で補間 )

//  プロトタイプ宣言
void S_Spline( double *, double *, int, double *, double *, int,
              int, double, int, double, double * );
int S_TriDiag( double *, double *, double *, double *, int, int );

//  メイン関数
int main( void ){
   double dx,xint[NINT+1],yint[NINT+1],ydash[NP];
   int i;
   //  ======= sin 関数を補間する場合 ======
   //  境界条件の挿入
   int  bcs = 0;        //  始点は自然条件
   int  bce = 0;        //  終点は自然条件
   double yds = 0.0, yde = -1.0;   // 端末条件が自由条件につき、この値はダミー
   double xdata[NP]={-1.0, -0.8, -0.6, -0.4, -0.2, 0.0, 0.2, 0.4, 0.6, 0.8, 1.0}; // x座標
   double ydata[NP]={0.038461538461538464, 0.058823529411764705, 0.1, 0.2, 0.5, 1.0, 0.5, 0.2, 0.1, 0.058823529411764705, 0.038461538461538464};        // y座標
   //  =================================
   //  全区間を NINT 等分して補間点を設定
   dx=(xdata[NP-1]-xdata[0])/NINT;
   xint[0]=xdata[0];
   for( i=1; i<=NINT;  i++)  xint[i]=xdata[0]+dx*i;  //  補間点のx座標
  
   //  3次スプライン補間により、補間点y座標を求める
   S_Spline(xdata,ydata,NP,xint,yint,NINT+1,bcs,yds,bce,yde,ydash);

   //  補間点をプリント
   //printf("      x      y   \n");
   FILE *file;
   file = fopen("suuti3-3.dat","w");
   for(i=0; i<=NINT; i++){
        fprintf(file,"%lf %lf\n",xint[i],yint[i]);    
    }
   fclose(file); 
   return 0;
}

void S_Spline(double x[],double y[],int n,double xint[],double yint[],
      int no,int bcs, double yds, int bce, double yde,double ydash[]){
    int i,j,status;
    double ai,bi,ci,di,dx,*a,*b,*c,*h;
    a=(double *)calloc(n, sizeof(double));    // 配列の動的確保
    b=(double *)calloc(n, sizeof(double));
    c=(double *)calloc(n, sizeof(double));
    h=(double *)calloc(n, sizeof(double));  

    for(i=0; i<n-1; i++)  h[i]=x[i+1]-x[i];
    //  始点における境界条件の挿入
    a[0] = 0.0;
    if(bcs == 0)  // 自然条件の場合
    {  
        b[0] = 2.0*h[0]; 
        c[0] = h[0]; 
        ydash[0] = 3.0*(y[1]-y[0]);
    }
    if(bcs==1)    // 固定条件の場合
    { 
        b[0] = 1.0;    
        c[0] = 0.0;  
        ydash[0] = yds; 
    }
    //  中間の節点での係数    
    for(i=1; i<n-1; i++)
    {
        a[i] = h[i];   
        b[i] = 2.0*(h[i-1]+h[i]);   
        c[i] = h[i-1];
        ydash[i]=3.0*((y[i]-y[i-1])*h[i]/h[i-1]+(y[i+1]-y[i])*h[i-1]/h[i]);
    }
    //   終点における境界条件の挿入
    c[n-1] = 0.0; 
    if(bce==0)   //  自然条件の挿入
    { 
        a[n-1] = h[n-2];   
        b[n-1] = 2.0*h[n-2];
        ydash[n-1] = 3.0*(y[n-1]-y[n-2]);
    }
    if(bce==1)   //  固定条件の挿入
    {
        a[n-1] = 0.0; 
        b[n-1] = 1.0; 
        ydash[n-1] = yde;
    }   
    //   ３重対角係数行列をもつ連立方程式の解析
    status = S_TriDiag( b, c, a, ydash, n, 0 );
    if( status == 0 ){
        //  for(i=0;i<n;i++) printf(" %d %f \n",i,ydash[i]); 
        //   補間値の計算
        for(j=0, i=0; i<n-1; i++){
            ai=(2.0*(y[i]-y[i+1])/h[i]+ydash[i]+ydash[i+1])/(h[i]*h[i]);
            bi=(3.0*(y[i+1]-y[i])/h[i]-2.0*ydash[i]-ydash[i+1])/h[i];
            ci=ydash[i];
            di=y[i]; 
	    while( xint[j] < x[i+1] )
            {
                dx=xint[j]-x[i];                   // 補間されるx座標
                yint[j]=dx*(dx*(dx*ai+bi)+ci)+di;  // 補間されたy座標
                if( j < no ){ j++;}
	    }
	    yint[no-1] = y[n-1]; 
	    //     printf(" %d %d %f \n",j,i,yint[j]);  
       }
    }
}

int S_TriDiag( double diag[], double upp[], double low[], double righ[], int n, 
     int dec)
{
    int i;
    double Tiny=1.0e-8;
    for(i=0; i<n; i++){
       if( diag[i] < Tiny ){ return 9;  }
    }

    if( dec == 0 ){   //   LU-分解  
        upp[0] /= diag[0];
        for(i=1; i<n-1; i++){
            diag[i] -= upp[i-1]*low[i];      
            upp[i] /= diag[i];
        }
        diag[n-1] -= upp[n-2]*low[n-1];
    }
    //    前進代入
    righ[0] /= diag[0];  
    for(i=1; i<n; i++)  righ[i] = (righ[i]-low[i]*righ[i-1])/diag[i]; 
    //    後退代入
    for(i=n-2; i>=0; i--)  righ[i] -= righ[i+1]*upp[i]; 
    return 0;
}