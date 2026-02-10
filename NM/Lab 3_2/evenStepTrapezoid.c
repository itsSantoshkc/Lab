#include <stdio.h>
#include <math.h>

double f(double x){
    return x * exp(sin(x));
}
int main(){
    double a = 1.0, b = 6.0;
    int n, i;
    printf("Enter number of intervals : ");
    scanf("%d", &n);
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (i = 1; i < n; i++){
        double xi = a + i * h;
        sum += 2 * f(xi);
    }
    double integral = (h / 2.0) * sum;
    printf("\n Approximate integral = %.6lf\n", integral);
    return 0;
}