#include <graphics.h>
#include <conio.h>

int main() {
    int gd = DETECT, gm;
    int tx = 100, ty = 50; 
    int scale_w = 50, scale_h = 25; 
    
    int x1 = 50, y1 = 50, x2 = 150, y2 = 100;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setbkcolor(WHITE);
    setcolor(DARKGRAY);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1, y1 - 15, "Original");

    x1 = x1 + tx;
    y1 = y1 + ty;
    x2 = x2 + tx ;
    y2 = y2 + ty ;

    setlinestyle(DASHED_LINE, 0, NORM_WIDTH);
    rectangle(x1, y1, x2, y2);
    outtextxy(x1, y1 - 15, "Translated & Scaled");

    getch();
    closegraph();
    return 0;
}