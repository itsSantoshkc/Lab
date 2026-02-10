#include <stdio.h>
#include <math.h>

// Define the function f(x) = e^x - 3x
double f(double x) {
return exp(x) - 3 * x;
}

// Define the derivative f'(x) = e^x - 3
double f_prime(double x) {
return exp(x) - 3;
}
int main()
{
    double x0, x1;
    double tol = 0.0001; // tolerance (accuracy)
    int maxIter = 1000, iter = 0;
    // Initial guess
    printf("Enter initial guess: ");
    scanf("%lf", &x0);
    printf("\nIter\t x0\t\t f(x0)\t\t x1\n");
    while (iter < maxIter)
    {
        if (fabs(f_prime(x0)) < 1e-8)
        {
            printf("Derivative too small. Method fails.\n");
            return 1;
        }
        x1 = x0 - f(x0) / f_prime(x0);
        printf("%d\t %.6f\t %.6f\t %.6f\n", iter + 1, x0, f(x0), x1);
        if (fabs(x1 - x0) < tol)
        {
            break; // Converged
        }

        x0 = x1;
        iter++;
    }
    printf("\nApproximate root = %.6f\n", x1);
    return 0;
}