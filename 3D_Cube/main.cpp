#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
float rx = 0.0;
float ry = 0.0;
float rz = 0.0;
float r = 10.0;

void reshape(int width, int height){
  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (double)width/(double)height, 1.0, 200.0);

}
void cube(){
   ///front
  glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,3);
      glVertex3f(-3,3,3);
      glVertex3f(-3,-3,3);
      glVertex3f(3,-3,3);
    glEnd();
  glPopMatrix();

   ///back
  glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,-3);
      glVertex3f(-3,3,-3);
      glVertex3f(-3,-3,-3);
      glVertex3f(3,-3,-3);
    glEnd();
  glPopMatrix();

  ///left side
  glPushMatrix();
    glColor3f(0.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,3,3);
      glVertex3f(-3,3,-3);
      glVertex3f(-3,-3,-3);
      glVertex3f(-3,-3,3);
    glEnd();
  glPopMatrix();

  ///right side
  glPushMatrix();
    glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(3,3,3);
      glVertex3f(3,3,-3);
      glVertex3f(3,-3,-3);
      glVertex3f(3,-3,3);
    glEnd();
  glPopMatrix();

  ///top side
  glPushMatrix();
    glColor3f(0.5f,0.7f,1.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,3,-3);
      glVertex3f(3,3,-3);
      glVertex3f(3,3,3);
      glVertex3f(-3,3,3);
    glEnd();
  glPopMatrix();

  ///bottom side
  glPushMatrix();
    glColor3f(1.0f,1.0f,0.0f);
    glBegin(GL_QUADS);
      glVertex3f(-3,-3,-3);
      glVertex3f(3,-3,-3);
      glVertex3f(3,-3,3);
      glVertex3f(-3,-3,3);
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
  cube();


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
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    //glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("3D Object");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(myKey);

    glutMainLoop();

    return EXIT_SUCCESS;
}
