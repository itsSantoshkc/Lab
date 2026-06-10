#include <graphics.h>

typedef struct{float x1,y1,x2,y2;}R;

void w2v(float x,float y,R w,R v,int *sx,int *sy){
    *sx = v.x1 + (x-w.x1)*(v.x2-v.x1)/(w.x2-w.x1);
    *sy = v.y2 - (y-w.y1)*(v.y2-v.y1)/(w.y2-w.y1);
}

void poly(float *x,float *y,int n,R w,R v,int style){
    int i,a,b,ax,ay,bx,by;
    setlinestyle(style,0,1);
    for(i=0;i<n;i++){
        a=i; b=(i+1)%n;
        w2v(x[a],y[a],w,v,&ax,&ay);
        w2v(x[b],y[b],w,v,&bx,&by);
        line(ax,ay,bx,by);
    }
    setlinestyle(SOLID_LINE,0,1);
}

void circleW(float cx,float cy,float r,R w,R v){
    int sx,sy;
    float s=(v.x2-v.x1)/(w.x2-w.x1);
    w2v(cx,cy,w,v,&sx,&sy);
    circle(sx,sy,(int)(r*s));
}

int main(){
    int gd=DETECT,gm;
    R w={-200,-150,200,150},
      v1={20,80,360,520},
      v2={420,160,740,440};

    float tx[]={-140,0,140}, ty[]={-80,120,-80};
    float sx[]={30,180,180,30}, sy[]={-100,-100,50,50};
    float cx=-160,cy=80,r=55;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    cleardevice();

    rectangle(v1.x1,v1.y1,v1.x2,v1.y2);
    rectangle(v2.x1,v2.y1,v2.x2,v2.y2);

    outtextxy(v1.x1,v1.y1-14,"Viewport 1");
    outtextxy(v2.x1,v2.y1-14,"Viewport 2");

    poly(tx,ty,3,w,v1,SOLID_LINE);
    poly(tx,ty,3,w,v2,SOLID_LINE);

    poly(sx,sy,4,w,v1,DASHED_LINE);
    poly(sx,sy,4,w,v2,DASHED_LINE);

    circleW(cx,cy,r,w,v1);
    circleW(cx,cy,r,w,v2);

    outtextxy(10,10,"Window-to-Viewport Transformation");

    getch();
    closegraph();
}