#include<stdio.h>
#include<math.h>

float zyunban(){
    float answer = 0;
    int i;
    for (i=1;i<=8000;i++){
        answer+=1.0f/(i*i);
    }
    return answer;}

float gyakuzyun(){
    float answer = 0;
    int i;
    for (i=8000;i>=1;i--){
        answer+=1.0f/(i*i);
    }
    return answer;}

float honto(){
    return (M_PI * M_PI)/6.0;}

int main(){
    printf("順番:%.7f\n",zyunban());
    printf("逆順:%.7f\n",gyakuzyun());
    printf("本当:%.7f\n",honto());
}