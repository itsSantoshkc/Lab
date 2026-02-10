#include<stdio.h>
#include<math.h>

float f(float x,float  y){
	return x + y;
}

int main(){
	float x0,y0,x,y,h;
	int n,i;
	printf("Enter initial value of x: ");
	scanf("%f",&x0);	
	printf("Enter initial value of y: ");
	scanf("%f",&y0);
	printf("Enter step size h: ");
	scanf("%f",&h);
	printf("Enter value of x at which y is required: ");
	scanf("%f",&x);
	printf("Enter number of Picard iteration ");
	scanf("%d",&n);
	h = (x- x0) /n;
	float y_prev = y0,y_new;
	for(i = 1;i<=n;i++){
		y_new = y0 + (h/2) * (f(x0,y_prev) + f(x,y_prev));
	}
	printf("\nApproximate solution at x = %.3f is u = %.5f\n",x,y_new);
	return 0;
}

