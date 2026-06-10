    /*
    * Program 7: 2D Scaling Transformation
    * C89 | graphics.h (BGI)
    *
    * Scaling about fixed point (fx, fy):
    *   x' = fx + sx * (x - fx)
    *   y' = fy + sy * (y - fy)
    *
    * Compile:
    *   gcc -o 07 07_2d_scaling.c -lbgi -lgdi32
    */

    #include <graphics.h>
    #include <stdio.h>

    #define N 4

    int main(void)
    {
        int gd = DETECT, gm;
        int H;
        int origX[N], origY[N];
        int scX[N],   scY[N];
        int fx, fy;
        float sx, sy;
        int i, j;
        char buf[80];

        origX[0] = 200; origX[1] = 320; origX[2] = 320; origX[3] = 200;
        origY[0] = 160; origY[1] = 160; origY[2] = 280; origY[3] = 280;

        fx = 200; fy = 160;
        sx = 2.0f;
        sy = 1.5f;

        initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
        H = getmaxy();

    setbkcolor(WHITE);
        cleardevice();
        
        /* Explicitly set the color to something highly visible like RED */
        setcolor(RED);

        for (i = 0; i < N; i++) {
            scX[i] = (int)(fx + sx * (origX[i] - fx));
            scY[i] = (int)(fy + sy * (origY[i] - fy));
        }

        /* Reference lines from fixed point to original corners */
        setlinestyle(DOTTED_LINE, 0, 1);
        for (i = 0; i < N; i++)
            line(fx, fy, origX[i], origY[i]);

        /* Original (solid) */
        setlinestyle(SOLID_LINE, 0, 1);
        for (i = 0; i < N; i++) {
            j = (i + 1) % N;
            line(origX[i], origY[i], origX[j], origY[j]);
        }
        outtextxy(origX[0], origY[0] - 15, "Original");

        /* Scaled (dashed) */
        setlinestyle(DASHED_LINE, 0, 1);
        for (i = 0; i < N; i++) {
            j = (i + 1) % N;
            line(scX[i], scY[i], scX[j], scY[j]);
        }
        setlinestyle(SOLID_LINE, 0, 1);
        outtextxy(scX[1] + 5, scY[1] - 15, "Scaled");

        /* Fixed point marker */
        circle(fx, fy, 5);
        outtextxy(fx + 7, fy - 7, "Fixed Pt");

        sprintf(buf, "sx = %.1f,  sy = %.1f   Fixed = (%d, %d)", sx, sy, fx, fy);
        outtextxy(10, 10, "2D Scaling Transformation");
        outtextxy(10, 28, buf);
        outtextxy(10, H - 20, "Solid = Original   Dashed = Scaled");

        getch();
        closegraph();
        return 0;
    }
