#include<stdio.h>
#include<math.h>
int is_one(double x,double y);
int judg(double x, double y);

int main(){
    FILE *file;
    file = fopen("suuti2-2-1.dat","w");
    double x=-2.0-4.0/499.0;
    for(int i=0;i<500;i++){
        x+=4.0/499.0;
        double y=-2.0-4.0/499.0;
        for(int j=0;j<500;j++){
            y+=4.0/499.0;
            if(x==0 && y==0){
                continue;
            }
            if(judg(x,y)){
                //printf("x=%f,y=%f\n",x,y);
                fprintf(file,"%f %f\n",x,y); 
            }
            //printf("x=%f,y=%f\n",x,y);
        }

    }
    fclose(file);
    return 0;
}
int is_one(double x,double y){
    return sqrt(pow(x-1,2)+pow(y,1))<1.0e-6;
}

int judg(double x,double y){
    double x_new;
    double y_new;
    int tmp=0;
    while(1){
        x_new =x-x/3+(pow(x,2)-pow(y,2))/(3*pow(pow(x,2)+pow(y,2),2));
        y_new =y-y/3-(2*x*y)/(3*pow(pow(x,2)+pow(y,2),2));
        tmp +=1;
        if(fabs(x_new-x)<1.0e-6 && fabs(y_new-y)<1.0e-6){
            return is_one(x_new,y_new);
        }
        x=x_new;
        y=y_new;
        if(tmp>1000){
            return 0;
        }
    }
}