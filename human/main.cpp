#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include<windows.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<math.h>

#define PI 3.1416

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

void circle(float radiusX, float radiusY, float z,int loop){
    float angle=0.0;
    glPushMatrix();
        glBegin(GL_POLYGON);
            for(int i=0; i<loop; i++){
                angle = 2*PI*i/100;
                glVertex3d(radiusX*cos(angle),radiusY*sin(angle),z);
            }
        glEnd();
    glPopMatrix();
}

void hair_triangle(){
    glBegin(GL_TRIANGLES);
        glVertex3d(0,2.4,2);
        glVertex3d(0.2,2,2);
        glVertex3d(-0.3,2,2);
    glEnd();
 }

void head(){
    ///head
    glColor3ub(238,213,183);
    glScaled(0.9,1.0,0.01);
    glutSolidTorus(0.7, 0.7,10,10);
    //circle(1.2,1.3,1,1100);
    ///hair
    glColor3ub(0,0,0);
    glPushMatrix();
        circle(1.3,1.4,1.1,50);
    glPopMatrix();
    glPushMatrix();
        glTranslated(-0.4,-0.5,1);
        glRotated(45,1,1,0);
        ///circle(0.5,0.5,50);
    glPopMatrix();

    ///neck
    glColor3ub(238,213,183);
    glTranslated(0,-1.2,0);
    glScaled(0.6,1.0,0.01);
    glutSolidTorus(0.6, 0.6,10,10);
}

void half_body(){
    glBegin(GL_POLYGON);
        glVertex3d(0,0,1);
        glVertex3d(1.2,0.3,1);
        glVertex3d(2.5,-0.5,1);
        glVertex3d(2.5,-1.5,1);
        glVertex3d(1.8,-1.5,1);
        //glVertex3d(1.8,-0.5,1);
        //glVertex3d(1.9,-2.5,1);
        //glVertex3d(-1.9,-2.5,1);
        //glVertex3d(-1.8,-0.5,1);
        glVertex3d(-1.8,-1.5,1);
        glVertex3d(-2.5,-1.5,1);
        glVertex3d(-2.5,-0.5,1);
        glVertex3d(-1.2,0.3,1);
    glEnd();
}

void full_body(){
    glPushMatrix();
        glBegin(GL_POLYGON);
            glVertex3d(0,0,1);
            glVertex3d(1.2,0.3,1);
            glVertex3d(2.7,-0.3,1);
            glVertex3d(3.5,-1.5,1);
            glVertex3d(2.5,-1.7,1);
            glVertex3d(2,-1,1);
            glVertex3d(2,-2.7,1);
            glVertex3d(-2,-2.7,1);
            glVertex3d(-2,-1,1);
            glVertex3d(-2.5,-1.7,1);
            glVertex3d(-3.5,-1.5,1);
            glVertex3d(-2.7,-0.3,1);
            glVertex3d(-1.2,0.3,1);
        glEnd();
    glPopMatrix();

    ///legs
    glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_POLYGON);
           glVertex3d(2,-2.7,1);
           glVertex3d(2,-5.5,1);
           glVertex3d(0.5,-5.5,1);
           glVertex3d(0.5,-3,1);
           glVertex3d(-0.5,-3,1);
           glVertex3d(-0.5,-5.5,1);
           glVertex3d(-2,-5.5,1);
           glVertex3d(-2,-2.7,1);
        glEnd();
    glPopMatrix();


}

void human_for_stall(){
    ///head
    head();
    ///body
    glPushMatrix();
        glColor3ub(0,0,255);
        glTranslated(0,-0.7,0);
        //glScaled(0.6,1.0,0.8);
        half_body();
    glPopMatrix();



}



void human(){
    glPushMatrix();
        glTranslated(2,0,1);
        head();
        glColor3ub(255,0,0);
        glTranslated(0,-0.7,0);
        full_body();
        //human_for_stall();

    glPopMatrix();
}

void myDisplay(){
  glClearColor(1,1,1,0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glPushMatrix();
    glTranslated(-2,2,-20);
    glRotated(r,0,1,0);
    //glTranslated(-2,2,-20);
    //glRotated(30,0,1,0);
    human_for_stall();
  glPopMatrix();


  glPushMatrix();
    glTranslated(2,2,-20);
    glRotated(r,0,1,0);
    human();
  glPopMatrix();


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
