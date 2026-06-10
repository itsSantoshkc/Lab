#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        int e2;
        putpixel(x1, y1, WHITE);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 <  dx) { err += dx; y1 += sy; }
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

    bresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}