#include <stdio.h>

int main(){
    int n;
    printf("Enter number of equation : ");
    scanf("%d", &n);
    float a[20][21];
    printf("Enter augmented matrix (A|B):\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            scanf("%f", &a[i][j]);
        }
    }
    for (int k = 0; k < n; k++){
        float pivot = a[k][k];
        if (pivot == 0.0){
            printf("Mathematical Error : Zero pivot detected");
            return 1;
        }
        for (int j = 0; j <= n; j++) {
            a[k][j] /= pivot;
        }
        for (int i = 0; i < n; i++){
            if (i != k){
                float factor = a[i][k];
                for (int j = 0; j <= n; j++){
                    a[i][j] -= factor * a[k][j];
                }
            }
        }
    }
    printf("\nSolution : \n");
    for (int i = 0; i < n; i++){
        printf("x[%d] = %.6f\n", i, a[i][n]);
    }
}