#include <GL/glut.h>

int w = 500, h = 500;

void square() {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
        glVertex2i(150,150);
        glVertex2i(350,150);
        glVertex2i(350,350);
        glVertex2i(150,350);
    glEnd();
}

void put(int x,int y,float r,float g,float b){
    glColor3f(r,g,b);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void fill(int x,int y){
    unsigned char c[3];
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,c);

    if(c[0]!=255 || c[1]!=255 || c[2]!=255) return;

    put(x,y,1,0,0);

    fill(x+1,y); 
    fill(x-1,y);
    fill(x,y+1); 
    fill(x,y-1);
}

void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    square();
    glFlush();

    fill(200,200);

    glFlush();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,w,0,h);
}

int main(int a,char** b){
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutCreateWindow("Flood Fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}