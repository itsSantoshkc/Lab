// The distance travelld by a car at various time interval are given as follows
// |t(sec)   | 1.5   | 2.0 | 2.5    | 3.0 | 3.5    | 4.0 |
// |y(meter) | 3.375 | 7.0 | 13.625 | 24  | 38.875 | 59  |

#include <stdio.h>

int main()
{
    float t[] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
    float y[] = {3.375, 7.0, 13.625, 24, 38.875, 59};
    float h = t[1] - t[0];

    float veloctiy, acceleration;

    veloctiy = (-3 * y[0] + 4 * y[1] - y[2]) / (2 * h);
    acceleration = (y[0] - 2 * y[1] + y[2]) / (h * h);

    printf(" Velocity at t = 1.5 s  : %.4f m/s\n", veloctiy);
    printf(" Acceleration at t = 1.5 s  : %.4f m/s^2\n", acceleration);

    return 0;
}