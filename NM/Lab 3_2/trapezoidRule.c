#include<stdio.h>

int main(){
    int n,i;
    printf("Enter number of data points : ");
    scanf("%d",&n);
    double x[n],y[n];
    printf("Enter x and u balues :\n");
    for(i = 0;i<n;i++){
        printf("x[%d]  y[%d]: ",i,i);
        scanf("%lf %lf",&x[i],&y[i]);
    }
    double h,sum = 0.0;
    h = x[1] - x[0];
    sum = y[0] + y[n - 1];
    for(i = 1;i<n- 1;i++){
        sum+= 2 * y[i];
    }
    double integral = (h/2.0) * sum;
    printf("\n Approximate integral = %.6lf\n",integral);
    return 0;
}