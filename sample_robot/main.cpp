#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
void init(){
    glClearColor(1,1,0.8,1);
    glOrtho(-50,50,-50,50,-5,5);
}
void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,0);
    glVertex2d(-12,24);
    glVertex2d(12,24);
    glVertex2d(12,9);
    glVertex2d(-12,9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex2d(12,21);
    glVertex2d(12,13);
    glVertex2d(15,13);
    glVertex2d(15,21);
    glVertex2d(-12,21);
    glVertex2d(-12,13);
    glVertex2d(-15,13);
    glVertex2d(-15,21);
    glColor3f(1,1,0);
    glVertex2d(5,9);
    glVertex2d(5,4);
    glVertex2d(-5,4);
    glVertex2d(-5,9);
    glColor3f(0,1,1);
    glVertex2d(-12,4);
    glVertex2d(12,4);
    glVertex2d(12,-15);
    glVertex2d(-12,-15);
    glColor3f(0,0,0);
    glVertex2d(12,3);
    glVertex2d(18,3);
    glVertex2d(12,-5);
    glVertex2d(18,-5);
    glVertex2d(-12,3);
    glVertex2d(-18,3);
    glVertex2d(-12,-5);
    glVertex2d(-18,-5);
    glColor3f(0,1,0);
    glVertex2d(-8,-15);
    glVertex2d(-3,-15);
    glVertex2d(-3,-24);
    glVertex2d(-8,-24);
    glVertex2d(8,-15);
    glVertex2d(3,-15);
    glVertex2d(3,-24);
    glVertex2d(8,-24);
    glColor3f(1,0,1);
    glVertex2d(-3,-24);
    glVertex2d(-8,-24);
    glVertex2d(-10,-26);
    glVertex2d(-4,-26);
    glVertex2d(3,-24);
    glVertex2d(8,-24);
    glVertex2d(10,-26);
    glVertex2d(4,-26);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0,0,0);
    glVertex2d(-3,18);
    glVertex2d(-9,18);
    glVertex2d(-6,21);
    glVertex2d(3,18);
    glVertex2d(9,18);
    glVertex2d(6,21);
    glColor3f(0,0,1);
    glVertex2d(13,-7);
    glVertex2d(18,-7);
    glVertex2d(16,-9);
    glVertex2d(-13,-7);
    glVertex2d(-18,-7);
    glVertex2d(-16,-9);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2d(0,12);
    glVertex2d(8,15);
    glVertex2d(0,11);
    glVertex2d(-8,15);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2d(0,17);
    glVertex2d(0,14);
    glVertex2d(6,30);
    glVertex2d(6,24);
    glVertex2d(-6,30);
    glVertex2d(-6,24);
    glColor3f(0,0,0);
    glVertex2d(14,-5);
    glVertex2d(14,-7);
    glVertex2d(16,-5);
    glVertex2d(16,-7);
    glVertex2d(-14,-5);
    glVertex2d(-14,-7);
    glVertex2d(-16,-5);
    glVertex2d(-16,-7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2d(-6,0);
    glVertex2d(6,0);
    glColor3f(1,1,0);
    glVertex2d(8,-3);
    glColor3f(0,1,0);
    glVertex2d(8,-6);
    glColor3f(1,0,1);
    glVertex2d(8,-8);
    glVertex2d(6,-10);
    glColor3f(0,1,1);
    glVertex2d(-6,-10);
    glColor3f(0,1,0.7);
    glVertex2d(-8,-8);
    glVertex2d(-8,-6);
    glVertex2d(-8,-3);
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
