#include <stdio.h>
// Function to calculate factorial
float factorial(int n) {
float f = 1;
for (int i = 1; i <= n; i++)
f *= i;
return f;
}

int main() {
float x[20], y[20][20], xp, p, h, yp;
int n, i, j;

// Step 1: Input number of data points
printf("Enter number of data points: ");
scanf("%d", &n);

// Step 2: Input x and y values
printf("Enter values of x:\n");
for (i = 0; i < n; i++)
scanf("%f", &x[i]);

printf("Enter corresponding values of y:\n");
for (i = 0; i < n; i++)
scanf("%f", &y[i][0]);

// Step 3: Construct forward difference table
for (j = 1; j < n; j++) {
for (i = 0; i < n - j; i++) {
y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
}
}

// Display forward difference table

printf("\nFORWARD DIFFERENCE TABLE:\n");
for (i = 0; i < n; i++) {
printf("%0.2f", x[i]);
for (j = 0; j < n - i; j++)
printf("\t%0.2f", y[i][j]);
printf("\n");
}

// Step 4: Input value for interpolation
printf("\nEnter value of x for interpolation: ");
scanf("%f", &xp);

// Step 5: Apply Newton Forward Formula
h = x[1] - x[0];
p = (xp - x[0]) / h;
yp = y[0][0];

for (i = 1; i < n; i++) {
float term = y[0][i];
for (j = 0; j < i; j++)
term = term * (p - j);
yp = yp + term / factorial(i);
}

// Step 6: Display result

printf("\nInterpolated value at x = %.3f is %.3f\n", xp, yp);

return 0;
}