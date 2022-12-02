#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<iostream>
using namespace std;

float rx = 0.0;
float ry = 0.0;
float rz = 0.0;
float r = 0.0;

void reshape(int width, int height){
  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (double)width/(double)height, 1.0, 200.0);

}
void window(){
        glColor3f(0.55,0.29,0.15);
        glBegin(GL_POLYGON);
          glVertex3f(3,3,5.1);
          glVertex3f(-3,3,5.1);
          glVertex3f(-3,-3,5.1);
          glVertex3f(3,-3,5.1);
        glEnd();
}
void bus(){
   ///front
  glPushMatrix();
    glColor3f(1, 0.76, 0.14);
    glBegin(GL_POLYGON);
      glVertex3f(7,2.5,5);
      glVertex3f(-6,2.5,5);
      glVertex3f(-9,-2.5,5);
      glVertex3f(7,-2.5,5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5,0,0);
    glScaled(0.3,0.65,1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2,0.95,0);
    glScaled(0.3,0.3,1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.95,0);
    glScaled(0.3,0.3,1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,0.95,0);
    glScaled(0.3,0.3,1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.7,0.95,0);
    glScaled(0.3,0.3,1);
    window();
    glPopMatrix();

   ///back
  glPushMatrix();
    glColor3f(1, 0.76, 0.14);
    glBegin(GL_POLYGON);
      glVertex3f(7,2.5,-5);
      glVertex3f(-6,2.5,-5);
      glVertex3f(-9,-2.5,-5);
      glVertex3f(7,-2.5,-5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5,0.95,0);
    glScaled(0.3,0.3,-1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2,0.95,0);
    glScaled(0.3,0.3,-1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.3,0.95,0);
    glScaled(0.3,0.3,-1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5,0.95,0);
    glScaled(0.3,0.3,-1);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.7,0.95,0);
    glScaled(0.3,0.3,-1);
    window();
    glPopMatrix();

  ///left side
  glPushMatrix();
  glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
      glVertex3f(-6,2.5,5);
      glVertex3f(-6,2.5,-5);
      glVertex3f(-9,-2.5,-5);
      glVertex3f(-9,-2.5,5);
    glEnd();
    glPopMatrix();

    ///right side
  glPushMatrix();
  glPushMatrix();
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
      glVertex3f(6,2.5,5);
      glVertex3f(6,2.5,-5);
      glVertex3f(6,-2.5,-5);
      glVertex3f(6,-2.5,5);
    glEnd();
    glPopMatrix();



  ///top side
  glPushMatrix();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
      glVertex3f(-6,2.5,5);
      glVertex3f(7,2.5,5);
      glVertex3f(7,2.5,-5);
      glVertex3f(-6,2.5,-5);
    glEnd();
    glPopMatrix();


}
void myDisplay(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0,0,-20);
  glRotated(r,1,1,0);

  glScaled(0.75,0.75,0.75);
  bus();


  glutSwapBuffers();

}
void xRotate(){
    r+=0.1;
    glutPostRedisplay();
}
void myKey(unsigned char key,int x,int y){
  switch(key){
    case 'x':
      glutIdleFunc(xRotate);
      break;

    default:
      break;
  }




}

int main(int argc, char *argv[])
{
    cout << "Student ID: CSE 06908032"<<endl;
    cout << "Student Name: Rakiba Akter"<<endl;
    glutInit(&argc, argv);
    glutInitWindowSize(1100,700);
    //glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Rakiba_Akrer_06908032");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(myKey);

    glutMainLoop();

    return EXIT_SUCCESS;
}
