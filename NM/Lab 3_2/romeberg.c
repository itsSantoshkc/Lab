#include <stdio.h>
#include <math.h>
double f(double x){
    return log(x);
}
int main(){
    double a = 4.0, b = 5.2,R[10][10];
    int k = 5;       
    R[1][1] = (b - a) * (f(a) + f(b)) / 2.0;
    for (int i = 2; i < k; i++){
        int n = pow(2, i - 1);
        double h = (b - a) / n,sum = 0;
        for (int j = 1; j <= n / 2; j++){
            sum += f(a + (2 * j - 1) * h);
        }
        R[i][1] = R[i - 1][1] / 2.0 + h * sum;
        for (int j = 2; j <= i; j++){
            R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j - 1) - 1);
        }
    }
    printf("\nRomberg Integration Table:\n");
    for (int i = 1; i < k; i++){
        for (int j = 1; j <= i; j++){
            printf("%lf\t", R[i][j]);
        }
        printf("\n");
    }
    printf("\nApproximate value of integral = %.10lf\n", R[k-1][k-1]);
    return 0;
}

