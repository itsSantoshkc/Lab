#include<stdio.h>
#include<math.h>

float f(float x,float  y){
	return x + y;
}
int main(){
	float x0,y0,x,y,h,xn,yp;
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
		yp = y + h * f(x,y);
		y = y + (h/2) * (f(x,y) + f(x + h,yp));
		x = x+ h;
		printf("%0.4f\t%0.4f\n",x,y);
	}
	return 0;
}
