/* Program 6: 2D Rotation Transformation using graphics.h */
/* Rotates a shape about a pivot point (px, py) by angle theta */

#include <graphics.h>
#include <conio.h>
#include <math.h>

#define N 4
#define DEG2RAD (3.14159265 / 180.0)

void rotate2D(float x, float y, float px, float py, float rad,
              float *outX, float *outY) {
    float dx = x - px, dy = y - py;
    *outX = px + dx * cos(rad) - dy * sin(rad);
    *outY = py + dx * sin(rad) + dy * cos(rad);
}

int main(void) {
    int gd = DETECT, gm;
    float origX[N] = {300, 400, 400, 300};
    float origY[N] = {200, 200, 300, 300};
    float px = 350.0f, py = 250.0f;  /* Pivot (center of square) */
    float angleDeg = 45.0f;
    float angleRad;
    float rotX[N], rotY[N];
    int i, j;

    angleRad = angleDeg * DEG2RAD;

    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    setbkcolor(WHITE);
    cleardevice();
    
    for (i = 0; i < N; i++) {
        rotate2D(origX[i], origY[i], px, py, angleRad, &rotX[i], &rotY[i]);
    }

    setcolor(DARKGRAY);
    for (i = 0; i < N; i++) {
        j = (i + 1) % N;
        line((int)origX[i], (int)origY[i], (int)origX[j], (int)origY[j]);
        line((int)rotX[i], (int)rotY[i], (int)rotX[j], (int)rotY[j]);
    }

    getch();
    closegraph();
    return 0;
}
