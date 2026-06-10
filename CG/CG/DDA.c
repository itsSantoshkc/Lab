#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

void dda(int x1, int y1, int x2, int y2)
{
    float dx, dy, steps, x_inc, y_inc;
    float x = x1, y = y1;
    int i;

    dx = (float)(x2 - x1);
    dy = (float)(y2 - y1);

    if (fabs(dx) > fabs(dy))
        steps = (float)fabs(dx);
    else
        steps = (float)fabs(dy);

    x_inc = dx / steps;
    y_inc = dy / steps;

    for (i = 0; i <= (int)steps; i++)
    {
        putpixel((int)x, (int)y, WHITE);

        x += x_inc;
        y += y_inc;
    }
}

int main(void)
{
    int x1, y1, x2, y2;
    int gd = DETECT, gm;

    printf("Enter x1 y1: ");
    if (scanf("%d %d", &x1, &y1) != 2) return 1;

    printf("Enter x2 y2: ");
    if (scanf("%d %d", &x2, &y2) != 2) return 1;

    initgraph(&gd, &gm, "");

    dda(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}