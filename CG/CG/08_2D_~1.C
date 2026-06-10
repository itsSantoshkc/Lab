#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int  midY;
    int x1, y1,x2, y2,x3, y3,rx1,rx2,rx3,ry1,ry2,ry3; 

    
    /* Original Triangle Vertices */
     x1 = 100, y1 = 100;
     x2 = 150, y2 = 200;
     x3 = 50,  y3 = 200;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    setbkcolor(WHITE);

    midY = getmaxy() / 2;

    /* Draw X-axis for reference */
    setcolor(DARKGRAY);
    line(0, midY, getmaxx(), midY);

    /* Draw original triangle */
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x1, y1 - 10, "Original");

    /* Reflect about X-axis (midY) */
    /* Formula: y' = 2*ref - y */
     rx1 = x1, ry1 = 2 * midY - y1;
     rx2 = x2, ry2 = 2 * midY - y2;
     rx3 = x3, ry3 = 2 * midY - y3;

    /* Draw reflected triangle */
    setcolor(CYAN);
    setlinestyle(DASHED_LINE, 0, NORM_WIDTH);
    line(rx1, ry1, rx2, ry2);
    line(rx2, ry2, rx3, ry3);
    line(rx3, ry3, rx1, ry1);
    outtextxy(rx1, ry1 + 5, "Reflected");

    getch();
    closegraph();
    return 0;
}