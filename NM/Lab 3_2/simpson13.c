#include <stdio.h>
#include <math.h>
double f(double x){
    return 2 * pow(x, 3) + 2 * pow(x, 2) - 3 * x + 3;
}
int main(){
    double a, b, h, sum = 0.0;
    int n, i;
    printf("\nEnter lower limit a: ");
    scanf("%lf", &a);
    printf("\nEnter ipper limit b: ");
    scanf("%lf", &b);
    printf("\nEnter number of intervals (must be even) : ");
    scanf("%d", &n);
    if (n % 2 != 0){
        printf("\nError: Numer of intervals must be even");
        return 0;
    }
    h = (b - a) / n;
    double integral = f(a) + f(b);
    for (i = 1; i < n; i++){
        double x = a + i * h;
        if (i % 2 == 0){
            integral += 2 * f(x);
        }
        else{
            integral += 4 * f(x);
        }
    }
    integral = (h / 3) * integral;
    printf("\n Approximate value of integral = %.6lf\n", integral);
    return 0;
}


