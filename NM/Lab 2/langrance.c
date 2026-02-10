// Using Lagrange’s interpolation formula find the value of f(x) at x = 10 from following data
// |x   | 5  | 6  | 9  | 11 |
// |f(x)| 12 | 13 | 14 | 16 |

#include <stdio.h>
int main() {
int i, j, n = 4; // number of data points
float x[4] = {5, 6, 9, 11};
float y[4] = {12, 13, 14, 16};
float xp = 10; // value at which we want f(x)
float yp = 0, p;

// Apply Lagrange interpolation formula
for (i = 0; i < n; i++) {
p = 1;
for (j = 0; j < n; j++) {
if (j != i)
p *= (xp - x[j]) / (x[i] - x[j]);
}
yp += p * y[i];
}

printf("Interpolated value at x = %.2f is f(x) = %.4f\n", xp, yp);

return 0;
}