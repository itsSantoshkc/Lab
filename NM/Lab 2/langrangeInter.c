#include <stdio.h>
int main() {
int n, i, j;
float x[20], y[20], xp, yp = 0, p;

// Input number of data points
printf("Enter number of data points: ");
scanf("%d", &n);

// Input x and y values
printf("Enter data points (x and y):\n");
for (i = 0; i < n; i++) {
printf("x[%d] = ", i);
scanf("%f", &x[i]);
printf("y[%d] = ", i);
scanf("%f", &y[i]);
}
// Input interpolation point
printf("Enter the value of x for interpolation: ");
scanf("%f", &xp);
// Lagrange Interpolation formula
for (i = 0; i < n; i++) {
p = 1;
for (j = 0; j < n; j++) {
if (j != i)
p = p * (xp - x[j]) / (x[i] - x[j]);
}
yp = yp + p * y[i];
}
// Output the result

printf("\nInterpolated value at x = %.3f is %.3f\n", xp, yp);

return 0;
}