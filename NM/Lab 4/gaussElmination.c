#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of equation : ");
    scanf("%d", &n);
    float a[20][21], x[20];
    printf("Enter augmented matrix (A|B): \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    for (int k = 0; k < n; k++)
    {
        if (a[k][k] == 0.0)
        {
            printf("Mathematical Error : Zero pivot detected");
            return 1;
        }
        for (int i = k + 1; i < n; i++)
        {
            float m = a[i][k] / a[k][k];

            for (int j = k; j <= n; j++)
            {
                a[i][j] = a[i][j] - m * a[k][j];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    printf("\nSolution : \n");
    for (int i = 0; i < n; i++)
    {
        printf("x[%d] = %.6f\n", i, x[i]);
    }
    return 0;
}