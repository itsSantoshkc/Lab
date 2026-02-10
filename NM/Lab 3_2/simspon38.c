#include <stdio.h>
#include <math.h>

double f(double x){
      return x * exp(-x * x);
}
int main(){
    double a, b, sum = 0.0;
    int n, i;
    printf("\nEnter lower limit a: ");
    scanf("%lf", &a);
    printf("\nEnter upper limit b: ");
    scanf("%lf", &b);
    printf("\nEnter number of intervals (multiple of 3) : ");
    scanf("%d", &n);
    if (n % 3 != 0){
        printf("\nError: Numer of intervals must be even");
        return 0;
    }
    double h = (b - a) / n;
    double integral = f(a) + f(b);
    for (i = 1; i < n; i++){
        double x = a + i * h;
        if (i % 3 == 0){
            integral += 2 * f(x);
        }
        else{
            integral += 3 * f(x);
        }
    }
    integral = (3 * h / 8) * integral;
    printf("\n Approximate value of integral = %.6lf\n", integral);
    return 0;
}
