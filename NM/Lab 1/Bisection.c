#include <stdio.h>
#include <math.h>

double func(double x)
{
    return x * x * sin(x) + exp(-x) - 3;
}

int main()
{
    double a = -3.0, b = 1.0, c;
    double tolerance = 0.0001;
    int maxIterations = 100;
    int iterations = 0;

    if (func(a) * func(b) >= 0)
    {
        printf("Error: f(a) and f(b) must have opposite signs.\n");
        return 1;
    }

    printf("Bisection Method for x^2 sin(x) + e^(-x) = 3\n");

    while (fabs(b - a) >= tolerance && iterations < maxIterations)
    {
        c = (a + b) / 2;

        if (fabs(func(c)) < tolerance)
            break;

        if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;

        iterations++;
    }

    printf("Approximate root: %lf\n", c);
    printf("Number of iterations: %d\n", iterations);

    return 0;
}
