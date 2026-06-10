/*
 * Simple 3D Scaling Transformation
 * C89 | graphics.h
 */

#include <graphics.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265

float cube[8][3] = {
    {-50,-50,-50}, {50,-50,-50},
    {50,50,-50},   {-50,50,-50},
    {-50,-50,50},  {50,-50,50},
    {50,50,50},    {-50,50,50}
};

int edge[12][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};

void project(float x,float y,float z,int *sx,int *sy)
{
    float a = 30 * PI / 180;

    *sx = 320 + (int)(x - z*cos(a));
    *sy = 240 + (int)(-y + z*sin(a));
}

void drawCube(float sx,float sy,float sz,int style)
{
    int i,x1,y1,x2,y2;

    setlinestyle(style,0,1);

    for(i=0;i<12;i++)
    {
        int a=edge[i][0];
        int b=edge[i][1];

        project(
            cube[a][0]*sx,
            cube[a][1]*sy,
            cube[a][2]*sz,
            &x1,&y1
        );

        project(
            cube[b][0]*sx,
            cube[b][1]*sy,
            cube[b][2]*sz,
            &x2,&y2
        );

        line(x1,y1,x2,y2);
    }
}

int main()
{
    int gd=DETECT, gm;

    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    setbkcolor(WHITE);
    cleardevice();
    setcolor(BLUE);

    /* Original cube */
    drawCube(1,1,1,SOLID_LINE);
    outtextxy(180,120,"Original");

    /* Scaled cube */
    drawCube(1.5,2.0,0.5,DASHED_LINE);
    outtextxy(400,120,"Scaled");

    outtextxy(10,10,"3D Scaling Transformation");

    getch();
    closegraph();
    return 0;
}