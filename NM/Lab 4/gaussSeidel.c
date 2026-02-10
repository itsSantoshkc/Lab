#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k, maxIter;
    float A[20][20], b[20], x[20];
    float tol, sum, error, newVal, oldX_i;
    printf("Enter number of equations : ");
    scanf("%d", &n);
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
        error = 0.0;
        for (i = 0; i < n; i++)
        {
            oldX_i = x[i];
            sum = b[i];
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum -= A[i][j] * x[j];
                }
            }
            if (A[i][i] == 0)
            {
                printf("Error: Division by zero (diagonal element is 0) in equation %d.\n", i + 1);
                return 1;
            }
            newVal = sum / A[i][i];
            float current_error = fabs(newVal - oldX_i);
            if (current_error > error)
            {
                error = current_error;
            }
            x[i] = newVal;
        }
        if (error < tol)
        {
            printf("\nSolution converged after %d iterations (Gauss-Seidel Method): \n", k);
            for (i = 0; i < n; i++)
            {
                printf("x[%d] = %.6f\n", i, x[i]);
            }
            return 0;
        }
    }
    printf("\nMaximum number of iterations (%d) reached without convergence.\n", maxIter);
    printf("Approximate solution (Gauss-Seidel Method): \n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %.6f\n", i, x[i]);
    }
    return 0;
}