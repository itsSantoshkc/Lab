#include<stdio.h>
#include<math.h>
float f(float x,float  y){
	return x + y;
}
float df(float x,float y){
	return 1 + x + y;
}
int main(){
	float x0,y0,x,y,h,xn;
	printf("Enter initial value of x: ");
	scanf("%f",&x0);
	printf("Enter initial value of y: ");
	scanf("%f",&y0);
	printf("Enter step size h:");
	scanf("%f",&h);
	printf("Enter final value of x:");
	scanf("%f",&xn);
	printf("\n x\t\ty\n");
	printf("----------------------------\n");
	printf("%0.4f\t%0.4f\n",x,y);
	while(x <  xn){
		y = y + h *f(x,y) + (h * h /2) * df(x,y);
		x = x+ h;
		printf("%0.4f\t%0.4f\n",x,y);
	}
		return 0;
}
