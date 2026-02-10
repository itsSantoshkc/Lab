#include<stdio.h>
#include<math.h>


float f(float x){
    return cos(x);
}


int main(){
    float x = 0.75;
    float h = 0.01;
    float second_derivative;

    second_derivative =  (f(x + h) -  2 * f(x) + f(x - h) )/ (h * h);
    
    printf("f''(0.75) : %.6f\n",second_derivative);
    

    return 0;
}