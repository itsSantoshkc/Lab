#include <GL/glut.h>

int W = 500, H = 500;

int same(GLubyte a[3], GLubyte b[3]){
    return a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
}

void get(int x,int y,GLubyte c[3]){
    glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,c);
}

void put(int x,int y,GLubyte c[3]){
    glColor3ubv(c);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void fill(int x,int y,GLubyte f[3],GLubyte b[3]){
    GLubyte c[3];
    get(x,y,c);

    if(!same(c,b) && !same(c,f)){
        put(x,y,f);

        fill(x+1,y,f,b);
        fill(x-1,y,f,b);
        fill(x,y+1,f,b);
        fill(x,y-1,f,b);
    }
}

/* Draw black circle */
void circle(int xc,int yc,int r){
    glColor3ub(0,0,0); // black circle

    glBegin(GL_POINTS);
    for(int x=-r;x<=r;x++){
        for(int y=-r;y<=r;y++){
            if(x*x + y*y <= r*r)
                glVertex2i(xc + x, yc + y);
        }
    }
    glEnd();
}

/* Render text */
void renderText(){
    glColor3ub(0,0,0); // black text
    glRasterPos2i(10, 480);

    const char *msg = "Boundary Fill";

    for(int i = 0; msg[i] != '\0'; i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
    }
}

void display(){
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glClear(GL_COLOR_BUFFER_BIT);

    circle(250,250,80);

    renderText();

    GLubyte f[3] = {255,255,255}; // fill color (white)
    GLubyte b[3] = {0,0,0};       // boundary color (black)

    fill(250,250,f,b);

    glFlush();
}

int main(int a,char** b){
    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(W,H);
    glutCreateWindow("Boundary Fill");

    gluOrtho2D(0,W,0,H);

    glutDisplayFunc(display);
    glutMainLoop();
}