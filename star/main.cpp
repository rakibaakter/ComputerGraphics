/*
Assignment no 1.
*/
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(){
    glClearColor(0.32,0.54,0.54,1);
    glOrtho(-10,10,-10,10,-5,5);

}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2d(3,4);
        glVertex2d(0,-5);
        glVertex2d(-6,-2);
        glVertex2d(6,-2);
        glVertex2d(-5,4);
        glVertex2d(0,-5);
        glVertex2d(3,4);
        glVertex2d(-6,-2);
        glVertex2d(-5,4);
        glVertex2d(6,-2);
    glEnd();
    glFlush();

}

int main(){
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();


    return 0;
}
