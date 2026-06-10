/*
 * Program 11: 3D Translation Transformation
 * C89 | graphics.h (BGI)
 *
 * Formula:
 *   x' = x + tx,  y' = y + ty,  z' = z + tz
 *
 * Wireframe cube projected with simple isometric projection.
 *
 * Compile:
 *   gcc -o 11 11_3d_translation.c -lbgi -lgdi32 -lm
 */

#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define NVERT 8
#define NEDGE 12
#define ANG   (30.0f * 3.14159265f / 180.0f)

static int edges[NEDGE][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};

/* signs for each vertex: [-1/+1] on x,y,z */
static int signs[NVERT][3] = {
    {-1,-1,-1},{1,-1,-1},{1,1,-1},{-1,1,-1},
    {-1,-1, 1},{1,-1, 1},{1,1, 1},{-1,1, 1}
};

static void project(float x, float y, float z, int cx, int cy, int *sx, int *sy) {
    *sx = cx + (int)(x - z * cos(ANG));
    *sy = cy + (int)(-y + z * sin(ANG) * 0.5f);
}

static void drawCube(float ox, float oy, float oz, float s,
                     int cx, int cy, int style) {
    int i, ax, ay, bx, by, a, b;
    float vx[NVERT], vy[NVERT], vz[NVERT];
    for (i=0;i<NVERT;i++) {
        vx[i]=ox+signs[i][0]*s;
        vy[i]=oy+signs[i][1]*s;
        vz[i]=oz+signs[i][2]*s;
    }
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
    int gd=DETECT,gm,W,H,cx,cy,ax,ay,bx,by;
    float s=60.0f, tx=120.0f, ty=-70.0f, tz=50.0f;
    char buf[80];

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    W=getmaxx(); H=getmaxy(); cx=W/2; cy=H/2;
    setbkcolor(WHITE); cleardevice(); setcolor(RED);

    drawCube(0,0,0,s,cx,cy,SOLID_LINE);
    project(-s,-s,-s,cx,cy,&ax,&ay);
    outtextxy(ax-10,ay-14,"Original");

    drawCube(tx,ty,tz,s,cx,cy,DASHED_LINE);
    project(tx-s,ty-s,tz-s,cx,cy,&ax,&ay);
    outtextxy(ax-10,ay-14,"Translated");

    project(0,0,0,cx,cy,&ax,&ay);
    project(tx,ty,tz,cx,cy,&bx,&by);
    line(ax,ay,bx,by); circle(bx,by,4);

    sprintf(buf,"tx=%.0f  ty=%.0f  tz=%.0f",tx,ty,tz);
    outtextxy(10,10,"3D Translation Transformation");
    outtextxy(10,28,buf);
    outtextxy(10,H-20,"Solid = Original   Dashed = Translated   (isometric)");

    getch(); closegraph(); return 0;
}