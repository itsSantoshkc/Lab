#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159265f

void drawShape(int x[], int y[], int n) {
    int i;
    for (i = 0; i < n-1; i++) line(x[i],y[i],x[i+1],y[i+1]);
    line(x[n-1],y[n-1],x[0],y[0]);
}

void applyAndDraw(float m[3][3], int x[], int y[], int n,
                  int ox, int oy, char *label, int style) {
    int i, tx[10], ty[10];
    setlinestyle(style,0,1); setcolor(RED);
    for (i=0;i<n;i++) {
        tx[i]=(int)(m[0][0]*x[i]+m[0][1]*y[i]+m[0][2])+ox;
        ty[i]=(int)(m[1][0]*x[i]+m[1][1]*y[i]+m[1][2])+oy;
    }
    drawShape(tx,ty,n);
    outtextxy(tx[0],ty[0]-20,label);
}

int main() {
    int gd=DETECT,gm;
    int x[]={100,150,200}, y[]={200,100,200}, n=3;
    float c=cos(30*PI/180), s=sin(30*PI/180);

    float T[3][3]={{1,0,80},{0,1,0},{0,0,1}};
    float R[3][3]={{c,-s,0},{s,c,0},{0,0,1}};
    float S[3][3]={{1.5,0,0},{0,1.5,0},{0,0,1}};

    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
    setbkcolor(WHITE); cleardevice(); setcolor(RED);

    setlinestyle(SOLID_LINE,0,1);
    drawShape(x,y,n);
    outtextxy(80,210,"Original Shape");

    applyAndDraw(T,x,y,n,200,0,"After Translation",DOTTED_LINE);
    applyAndDraw(R,x,y,n,400,0,"After Rotation",DASHED_LINE);
    applyAndDraw(S,x,y,n,600,0,"After Scaling",USERBIT_LINE);

    getch(); closegraph(); return 0;
}