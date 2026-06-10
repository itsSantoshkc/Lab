#include <graphics.h>
#include <stdio.h>

#define N            4
#define SHEAR_MODE   0
#define SHEAR_FACTOR 0.5f

void drawPoly(int cx, int cy, int x[], int y[]) {
    int i;
    for (i = 0; i < N; i++)
        line(cx+x[i], cy+y[i], cx+x[(i+1)%N], cy+y[(i+1)%N]);
}

int main(void) {
    int gd=DETECT, gm, W, H, cx, cy, i;
    int ox[]={-80,80,80,-80}, oy[]={-80,-80,80,80};
    int sx[N], sy[N];
    float shf=SHEAR_FACTOR;
    char buf[80];

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    W=getmaxx(); H=getmaxy(); cx=W/2; cy=H/2;

    setfillstyle(SOLID_FILL,WHITE); bar(0,0,W,H);
    setcolor(BLACK);

    setlinestyle(DOTTED_LINE,0,1);
    line(0,cy,W,cy); line(cx,0,cx,H);
    setlinestyle(SOLID_LINE,0,1);
    outtextxy(W-20,cy-14,"+X"); outtextxy(cx+4,4,"+Y");

    for (i=0;i<N;i++) {
        sx[i] = SHEAR_MODE ? ox[i]              : (int)(ox[i]+shf*oy[i]);
        sy[i] = SHEAR_MODE ? (int)(oy[i]+shf*ox[i]) : oy[i];
    }

    setlinestyle(SOLID_LINE,0,1);  drawPoly(cx,cy,ox,oy);
    outtextxy(cx+ox[0]-10, cy+oy[0]-14, "Original");

    setlinestyle(DASHED_LINE,0,1); drawPoly(cx,cy,sx,sy);
    setlinestyle(SOLID_LINE,0,1);
    outtextxy(cx+sx[1]+5, cy+sy[1]+5, "Sheared");

    sprintf(buf, SHEAR_MODE ? "Y-Shear: x'= x,  y'= y + %.1f*x"
                            : "X-Shear: x'= x + %.1f*y,  y'= y", shf);
    outtextxy(10,10,"2D Shearing Transformation");
    outtextxy(10,26,buf);
    outtextxy(10,H-16,"Solid = Original   Dashed = Sheared");

    getch(); closegraph(); return 0;
}