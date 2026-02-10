#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j, k, maxIter;
    float A[20][20], b[20], x[20], newX[20];
    float tol, sum, error;
    printf("Enter number of equations : ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 20)
        return 1;
    printf("Enter coefficient matrix A and vector b : \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
        scanf("%f", &b[i]);
    }
    printf("Enter initial guess values : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter tolerance : ");
    scanf("%f", &tol);
    printf("Enter maximum number of iteration : ");
    scanf("%d", &maxIter);
    for (k = 1; k <= maxIter; k++)
    {
        for (i = 0; i < n; i++)
        {
            sum = b[i];
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            if (A[i][i] == 0.0)
            {
                printf("\nMathematical Error: Zero diagonal element detected in equation %d\n", i + 1);
                return 1;
            }
            newX[i] = sum / A[i][i];
        }
        error = 0.0;
        for (i = 0; i < n; i++)
        {
            float current_error = fabs(newX[i] - x[i]);
            if (current_error > error)
            {
                error = current_error;
            }
            x[i] = newX[i];
        }
        if (error < tol)
        {
            printf("\nSolution converged after %d iterations (Jacobi Method): \n", k);
            for (i = 0; i < n; i++)
            {
                printf("x[%d] = %.6f\n", i, x[i]);
            }
            return 0;
        }
    }
    printf("\nMaximum number of iterations (%d) reached without convergence.\n", maxIter);
    printf("Approximate solution (Jacobi Method): \n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %.6f\n", i, x[i]);
    }
    return 0;
}