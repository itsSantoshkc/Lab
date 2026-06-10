#include <graphics.h>
#include <conio.h>
#include <stdio.h>

void drawCirclePoints(int cx, int cy, int x, int y)
{
    putpixel(cx + x, cy + y, WHITE);
    putpixel(cx - x, cy + y, WHITE);
    putpixel(cx + x, cy - y, WHITE);
    putpixel(cx - x, cy - y, WHITE);
    putpixel(cx + y, cy + x, WHITE);
    putpixel(cx - y, cy + x, WHITE);
    putpixel(cx + y, cy - x, WHITE);
    putpixel(cx - y, cy - x, WHITE);
}

void midpointCircle(int cx, int cy, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    drawCirclePoints(cx, cy, x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCirclePoints(cx, cy, x, y);
    }
}

int main(void)
{
    int cx, cy, r;
    int gd = DETECT, gm;

    printf("Enter center (cx cy): ");
    if (scanf("%d %d", &cx, &cy) != 2) return 1;
    printf("Enter radius: ");
    if (scanf("%d", &r) != 1) return 1;

    initgraph(&gd, &gm, "");

    midpointCircle(cx, cy, r);

    getch();
    closegraph();
    return 0;
}