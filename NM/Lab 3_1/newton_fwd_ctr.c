#include<stdio.h>


float f(float x){
    return x * x;
}


int main(){
    float x = 1.0;
    float h = 0.2;
    float forward,central;

    forward =  (f(x + h) - f(x) )/ h;
    central =   (f(x + h) - f(x - h) )/ (2 * h);

    printf("Forward Difference appxox : %.4f\n",forward);
    printf("Central Difference appxox : %.4f\n",central);

    return 0;
}