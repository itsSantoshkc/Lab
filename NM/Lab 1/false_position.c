#include <stdio.h>
#include <math.h> // Required for pow() and fabs()
// Define the function f(x)
double f(double x)
{
    return pow(x, 2) - x - 2;
}
int main()
{
    double a, b, c, fa, fb, fc;
    double tolerance = 0.0001; // Desired accuracy
    int maxIterations = 100;   // Maximum number of iterations
    int iteration = 0;
    // Get initial guesses for 'a' and 'b' from the user
    printf("Enter the first guess (a): ");
    scanf("%lf", &a);
    printf("Enter the second guess (b): ");
    scanf("%lf", &b);
    // Check if the initial interval brackets the root
    fa = f(a);
    fb = f(b);
    if (fa * fb >= 0)
    {
        printf("Error: The function values at the initial guesses must have opposite signs.\n");
        return 1; // Indicate an error
    }
    printf("\nIteration\ta\t\tb\t\tc\t\tf(c)\n");
    printf("------------------------------------------------------------------\n");
    do
    {
        // Calculate the next approximation 'c' using the False Position formula
        c = (a * fb - b * fa) / (fb - fa);

        fc = f(c);
        printf("%d\t\t%.4lf\t\t%.4lf\t\t%.4lf\t\t%.4lf\n", iteration, a, b, c, fc);
        // Update the interval based on the sign of f(c)
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        iteration++;
    } while (fabs(fc) > tolerance && iteration < maxIterations);
    if (fabs(fc) <= tolerance)
    {
        printf("\nRoot found at x = %.4lf after %d iterations.\n", c, iteration);
    }
    else
    {
        printf("\nAlgorithm did not converge within the maximum number of iterations.\n");
    }
    return 0;
}