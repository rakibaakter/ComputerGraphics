/*
simple line drawing
 */

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(){
    glClearColor(1,0.75,0.79,1);
    glOrtho(-300,300,-300,300,-300,300);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    float x1,x2,y1,y2,m,b, lx,ly;
    x1=-150;
    x2=200;
    y1=-70;
    y2=180;
    lx=x1;
    ly=y1;
    m=(y2-y1)/(x2-x1);
    b=y1-m*x1;

    glBegin(GL_POINTS);
        glVertex2d(x1,y1);
        glVertex2d(x2,y2);
    glEnd();

    if(m<=1){
      while(lx<x2){
        lx=lx+1;
        ly =ly+m;

        glBegin(GL_POINTS);
            glVertex2d(lx,ly);
        glEnd();
      }


    }else{
        while(ly<y2){
            ly=ly+1;
            lx =lx+(1/m);

            glBegin(GL_POINTS);
                glVertex2d(lx,ly);
            glEnd();
        }
    }


    glFlush();
}

int main(){

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("RAKIBA");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();

    return 0;
}
