#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawEllipsePoints(int cx, int cy, int x, int y)
{
    putpixel(cx + x, cy + y, WHITE);
    putpixel(cx - x, cy + y, WHITE);
    putpixel(cx + x, cy - y, WHITE);
    putpixel(cx - x, cy - y, WHITE);
}

void midpointEllipse(int cx, int cy, int rx, int ry)
{
    long rx2 = (long)rx * rx;
    long ry2 = (long)ry * ry;
    long x = 0;
    long y = (long)ry;
    long p1, dx, dy, p2;

    p1 = ry2 - rx2 * (long)ry + (rx2 / 4);
    dx = 2 * ry2 * x;
    dy = 2 * rx2 * y;

    while (dx < dy)
    {
        drawEllipsePoints(cx, cy, (int)x, (int)y);
        x++;
        dx += 2 * ry2;
        if (p1 < 0)
            p1 += dx + ry2;
        else
        {
            y--;
            dy -= 2 * rx2;
            p1 += dx - dy + ry2;
        }
    }

    p2 = (long)(ry2 * ((double)x + 0.5) * ((double)x + 0.5) + rx2 * ((double)y - 1.0) * ((double)y - 1.0) - rx2 * ry2);

    while (y >= 0)
    {
        drawEllipsePoints(cx, cy, (int)x, (int)y);
        y--;
        dy -= 2 * rx2;
        if (p2 > 0)
            p2 += rx2 - dy;
        else
        {
            x++;
            dx += 2 * ry2;
            p2 += dx - dy + rx2;
        }
    }
}

int main(void)
{
    int cx, cy, rx, ry;
    int gd = DETECT, gm;

    printf("Enter center (cx cy): ");
    if (scanf("%d %d", &cx, &cy) != 2) return 1;
    printf("Enter rx (horizontal radius): ");
    if (scanf("%d", &rx) != 1) return 1;
    printf("Enter ry (vertical radius): ");
    if (scanf("%d", &ry) != 1) return 1;

    initgraph(&gd, &gm, "");

    midpointEllipse(cx, cy, rx, ry);

    getch();
    closegraph();
    return 0;
}