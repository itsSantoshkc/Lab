#include <graphics.h>
#include <conio.h>

int xmin1=50,ymin1=80,xmax1=250,ymax1=220;
int xmin2=350,ymin2=80,xmax2=550,ymax2=220;

int sx[]={100,170,210,150,60}, sy[]={50,30,130,240,180}, n=5;
#define MAX 20

int inside(int x,int y,int ex1,int ey1,int ex2,int ey2){
    return (long)(ex2-ex1)*(y-ey1)-(long)(ey2-ey1)*(x-ex1)>=0;
}

void inter(int x1,int y1,int x2,int y2,int ex1,int ey1,int ex2,int ey2,int *ix,int *iy){
    long A1=y2-y1,B1=x1-x2,C1=A1*x1+B1*y1;
    long A2=ey2-ey1,B2=ex1-ex2,C2=A2*ex1+B2*ey1;
    long d=A1*B2-A2*B1;
    if(!d){ *ix=x1; *iy=y1; return; }
    *ix=(C1*B2-C2*B1)/d;
    *iy=(A1*C2-A2*C1)/d;
}

int clip(int *px,int *py,int n,int ex1,int ey1,int ex2,int ey2,int *ox,int *oy){
    int i,cnt=0,cx,cy,nx,ny,ci,ni;

    for(i=0;i<n;i++){
        cx=px[i]; cy=py[i];
        nx=px[(i+1)%n]; ny=py[(i+1)%n];

        ci=inside(cx,cy,ex1,ey1,ex2,ey2);
        ni=inside(nx,ny,ex1,ey1,ex2,ey2);

        if(ci){ ox[cnt]=cx; oy[cnt++]=cy; }
        if(ci!=ni) inter(cx,cy,nx,ny,ex1,ey1,ex2,ey2,&ox[cnt],&oy[cnt]),cnt++;
    }
    return cnt;
}

void draw(int *x,int *y,int n,int c){
    int p[MAX*2],i;
    for(i=0;i<n;i++) p[2*i]=x[i],p[2*i+1]=y[i];
    p[2*n]=x[0]; p[2*n+1]=y[0];
    setcolor(c);
    drawpoly(n+1,p);
}

int main(){
    int gd=DETECT,gm,i,rx[MAX],ry[MAX],ox[MAX],oy[MAX],off,xn;

    initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
    cleardevice();

    outtextxy(90,55,"Before Clipping");
    rectangle(xmin1,ymin1,xmax1,ymax1);
    draw(sx,sy,n,DARKGRAY);

    outtextxy(390,55,"After Clipping");
    rectangle(xmin2,ymin2,xmax2,ymax2);

    off=xmin2-xmin1;
    for(i=0;i<n;i++) rx[i]=sx[i]+off, ry[i]=sy[i];

    xn=clip(rx,ry,n,xmin2,ymin2,xmax2,ymax2,ox,oy);
    if(xn) draw(ox,oy,xn,DARKGRAY);

    getch();
    closegraph();
}