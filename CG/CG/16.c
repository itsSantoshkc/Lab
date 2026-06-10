#include <graphics.h>
#include <conio.h>

#define INSIDE 0
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int xmin1=50,ymin1=80,xmax1=250,ymax1=220;
int xmin2=350,ymin2=80,xmax2=550,ymax2=220;

int code(int x,int y,int xmin,int ymin,int xmax,int ymax){
    int c=INSIDE;
    if(x<xmin) c|=LEFT; else if(x>xmax) c|=RIGHT;
    if(y<ymin) c|=TOP;  else if(y>ymax) c|=BOTTOM;
    return c;
}

void clip(int x1,int y1,int x2,int y2,int xmin,int ymin,int xmax,int ymax){
    int c1=code(x1,y1,xmin,ymin,xmax,ymax),
        c2=code(x2,y2,xmin,ymin,xmax,ymax),x,y,ok=0;

    while(1){
        if(!c1 && !c2){ ok=1; break; }
        if(c1 & c2) break;

        int c=c1?c1:c2;

        if(c & TOP){ x=x1+(x2-x1)*(ymin-y1)/(y2-y1); y=ymin; }
        else if(c & BOTTOM){ x=x1+(x2-x1)*(ymax-y1)/(y2-y1); y=ymax; }
        else if(c & RIGHT){ y=y1+(y2-y1)*(xmax-x1)/(x2-x1); x=xmax; }
        else { y=y1+(y2-y1)*(xmin-x1)/(x2-x1); x=xmin; }

        if(c==c1){ x1=x; y1=y; c1=code(x1,y1,xmin,ymin,xmax,ymax); }
        else { x2=x; y2=y; c2=code(x2,y2,xmin,ymin,xmax,ymax); }
    }

    if(ok){ setcolor(GREEN); line(x1,y1,x2,y2); }
}

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");

    cleardevice();

    outtextxy(100,40,"Before Clipping");
    setcolor(RED);
    rectangle(xmin1,ymin1,xmax1,ymax1);
    line(20,40,300,260);

    outtextxy(420,40,"After Clipping");
    rectangle(xmin2,ymin2,xmax2,ymax2);

    clip(320,40,600,260,xmin2,ymin2,xmax2,ymax2);

    getch();
    closegraph();
}