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
float r = 0.0;

void reshape(int width, int height){
  glViewport(0,0,width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0, (double)width/(double)height, 1.0, 200.0);

}

void stand(float x, float y){
    glPushMatrix();
        glColor3f(0.5,0.0f,0.0f);
        glBegin(GL_QUADS);
          glVertex3f(x-0.5,y,0);
          glVertex3f(x-0.5,y-12,0);
          glVertex3f(x,y-12,0);
          glVertex3f(x,y,0);
        glEnd();
   glPopMatrix();
}

void square_table(float x1, float y1, float x2, float y2){
    glPushMatrix();
        glBegin(GL_QUADS);
          glVertex3f(x1,y1,0);
          glVertex3f(x1,y2,0);
          glVertex3f(x2,y2,0);
          glVertex3f(x2,y1,0);
        glEnd();
   glPopMatrix();
}

void stall(){

    ///roof
    glPushMatrix();
        glColor3f(1.0f,0.92f,0.75f);
        glBegin(GL_QUADS);
          glVertex3f(6,6,0);
          glVertex3f(-6,6,0);
          glVertex3f(-10,2,0);
          glVertex3f(3,2,0);
        glEnd();
   glPopMatrix();


   ///triangle side
    glPushMatrix();
        glColor3f(1.0f,0.95f,0.80f);
        glBegin(GL_TRIANGLES);
          glVertex3f(6,6,0);
          glVertex3f(3,2,0);
          glVertex3f(10,4,0);
        glEnd();
   glPopMatrix();

   stand(-9.0,2.0);
   stand(3.0,2.0);
   stand(9.5,4.0);

   glPushMatrix();
        glColor3f(1.0f,0.95f,0.80f);
        glBegin(GL_QUADS);
          glVertex3f(2.5,-4,0);
          glVertex3f(2.5,-9.5,0);
          glVertex3f(9,-7.5,0);
          glVertex3f(9,-2,0);
        glEnd();
   glPopMatrix();

   square_table(3,-4,-9,-9.5);
   glColor3f(0.7f,0.5f,0.0f);
   square_table(3,-2,-9,-7.5);
   square_table(2.5,-2,9,-7.5);




}
void myDisplay(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslated(0,0,-20);
  glRotated(r,0,1,0);

  glScaled(0.75,0.75,0.75);
  stall();


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
    glutInitWindowSize(1024,720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("3D Object");
    glEnable(GL_DEPTH_TEST);
    glutReshapeFunc(reshape);
    glutDisplayFunc(myDisplay);

    glutKeyboardFunc(myKey);

    glutMainLoop();

    return EXIT_SUCCESS;
}
