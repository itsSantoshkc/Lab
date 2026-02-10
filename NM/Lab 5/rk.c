#include<stdio.h>
#include<math.h>

float f(float x,float  y){
	return x + y;
}
int main(){
	float x0,y0,x,y,h,xn,k1,k2,k3,k4;	
	printf("Enter initial value of x: ");
	scanf("%f",&x0);	
	printf("Enter initial value of y: ");
	scanf("%f",&y0);	
	printf("Enter step size h: ");
	scanf("%f",&h);
	printf("Enter the final value of x: ");
	scanf("%f",&xn);
	x = x0;
	y = y0;
	printf("\n x\t\ty\n");
	printf("----------------------------\n");
	printf("%0.4f\t%0.4f\n",x,y);
	while(x <  xn){
		k1 = h * f(x,y);
		k2 = h * f(x + h/2,y + k1/2);
		k3 = h * f(x + h/2,y + k2/2);
		k4 = h * f(x + h/2,y + k3);
		y = y + (1.0/6.0) * (k1 + 2*k2 + 2*k3 + k4);
		x = x+ h;
		printf("%0.4f\t%0.4f\n",x,y);
	}
		return 0;
}
