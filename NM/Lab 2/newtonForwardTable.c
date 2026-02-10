// Find the function value of x = 25 from the followinf data using forward difference table
// |x   | 10     | 20     | 30  | 40    |
// |f(x)| 0.1736 | 0.3420 | 0.5 | 0.766 |

#include <stdio.h>

// Function to calculate factorial
float factorial(int n) {
float f = 1;
for (int i = 1; i <= n; i++)
f *= i;
return f;
}

int main() {
int i, j, n = 5;
float x[5] = {10, 20, 30, 40, 50};
float y[5][5] = {
{0.1736, 0, 0, 0, 0},
{0.3420, 0, 0, 0, 0},
{0.5000, 0, 0, 0, 0},
{0.6428, 0, 0, 0, 0},
{0.7660, 0, 0, 0, 0}
};
float xp = 25, h, p, yp, term;

// Create forward difference table
for (j = 1; j < n; j++) {
for (i = 0; i < n - j; i++) {
y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
}
}

// Display forward difference table
printf("FORWARD DIFFERENCE TABLE:\n");
for (i = 0; i < n; i++) {
printf("%6.4f", x[i]);
for (j = 0; j < n - i; j++)
printf("\t%6.4f", y[i][j]);
printf("\n");
}

// Calculation using Newton's Forward Formula
h = x[1] - x[0];
p = (xp - x[0]) / h;
yp = y[0][0];

for (i = 1; i < n; i++) {
term = y[0][i];
for (j = 0; j < i; j++)
term = term * (p - j);

yp = yp + term / factorial(i);
}

// Display result
printf("\nValue of f(%.2f) = %.6f\n", xp, yp);

return 0;
}