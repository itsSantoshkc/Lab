/*
 * Program 12: 3D Rotation Transformation
 * C89 | graphics.h (BGI)
 *
 * Change AXIS (0=X, 1=Y, 2=Z) and ANGLE_DEG below.
 *
 * X-rotation:  y'= y*cos - z*sin,  z'= y*sin + z*cos
 * Y-rotation:  x'= x*cos + z*sin,  z'=-x*sin + z*cos
 * Z-rotation:  x'= x*cos - y*sin,  y'= x*sin + y*cos
 *
 * Compile:
 *   gcc -o 12 12_3d_rotation.c -lbgi -lgdi32 -lm
 */
#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define NVERT     8
#define NEDGE    12
#define AXIS      1
#define ANGLE_DEG 45.0f
#define ANG_ISO  (30.0f * 3.14159265f / 180.0f)

static int edges[NEDGE][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};
static int signs[NVERT][3] = {
    {-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},
    {-1,-1, 1},{1,-1, 1},{1,1, 1},{-1,1, 1}
};

static void project(float x, float y, float z, int cx, int cy, int *sx, int *sy) {
    *sx = cx + (int)(x - z * cos(ANG_ISO));
    *sy = cy + (int)(-y + z * sin(ANG_ISO) * 0.5f);
}

static void drawCube(float vx[], float vy[], float vz[], int cx, int cy, int style) {
    int i, ax, ay, bx, by, a, b;
    setlinestyle(style,0,1);
    for (i=0;i<NEDGE;i++) {
        a=edges[i][0]; b=edges[i][1];
        project(vx[a],vy[a],vz[a],cx,cy,&ax,&ay);
        project(vx[b],vy[b],vz[b],cx,cy,&bx,&by);
        line(ax,ay,bx,by);
    }
    setlinestyle(SOLID_LINE,0,1);
}

int main(void) {
    int gd=DETECT,gm,W,H,cx,cy,i,ax,ay;
    float s=70.0f, c,sn;
    float ovx[NVERT],ovy[NVERT],ovz[NVERT];
    float rvx[NVERT],rvy[NVERT],rvz[NVERT];
    float rad=ANGLE_DEG*3.14159265f/180.0f;
    char buf[80];

    c=cos(rad); sn=sin(rad);
    for (i=0;i<NVERT;i++) {
        ovx[i]=signs[i][0]*s;
        ovy[i]=signs[i][1]*s;
        ovz[i]=signs[i][2]*s;
    }

    for (i=0;i<NVERT;i++) {
        float x=ovx[i],y=ovy[i],z=ovz[i];
        switch(AXIS) {
            case 0: rvx[i]=x;      rvy[i]=y*c-z*sn; rvz[i]=y*sn+z*c;  break;
            case 1: rvx[i]=x*c+z*sn; rvy[i]=y;      rvz[i]=-x*sn+z*c; break;
            default:rvx[i]=x*c-y*sn; rvy[i]=x*sn+y*c; rvz[i]=z;       break;
        }
    }

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    W=getmaxx(); H=getmaxy(); cx=W/2; cy=H/2;
    setbkcolor(WHITE); cleardevice(); setcolor(RED);

    drawCube(ovx,ovy,ovz,cx,cy,SOLID_LINE);
    project(ovx[0],ovy[0],ovz[0],cx,cy,&ax,&ay);
    outtextxy(ax-10,ay-14,"Original");

    drawCube(rvx,rvy,rvz,cx,cy,DASHED_LINE);
    project(rvx[1],rvy[1],rvz[1],cx,cy,&ax,&ay);
    outtextxy(ax+4,ay-14,"Rotated");

    sprintf(buf,"Axis = %s   Angle = %.1f degrees",
            (const char*[]){"X","Y","Z"}[AXIS], ANGLE_DEG);
    outtextxy(10,10,"3D Rotation Transformation");
    outtextxy(10,28,buf);

    getch(); closegraph(); return 0;
}