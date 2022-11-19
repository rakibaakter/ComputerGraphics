#include<windows.h>
#include<math.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#define PI 3.1416

//float cPositionX = -2;
//float cPositionY = 2;
float cx = 1;
float cy = 0;
float ca = 1;
float c1=1,c2=1,c3=1;
float cl1=0.5,cl2=0.51,cl3=0.52;
void init(){
    glClearColor(0,0.5,1.7,0);
    glOrtho(-5,5,-5,5,-5,5);
}
void circle(float radiusX, float radiusY){
    float angle=0.0;
    glBegin(GL_POLYGON);
        for(int i=0; i<100; i++){
            angle = 2*PI*i/100;
            glVertex2f(radiusX*cos(angle),radiusY*sin(angle));
        }
    glEnd();
}

void translatedCircle(float translateX, float translatedY){
    glPushMatrix();
            glScaled(0.5,0.5,1);
            glTranslated(translateX+cx,translatedY+cy,0);
            //glRotated(ca,0,0,-1);
                circle(1,1);
        glPopMatrix();
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);

    //glTranslated(cPositionX,cPositionY,0);
    glPushMatrix();
        glTranslated(-2,2,0);
        glPushMatrix();
            //cloud
            glColor3f(c1,c2,c3);
            translatedCircle(-1,0.5);
            translatedCircle(0.3,0.9);
            translatedCircle(1,0.6);
            translatedCircle(0,-0.5);
            translatedCircle(1.3,-0.5);
            translatedCircle(1.8,0.2);
        glPopMatrix();

    glPopMatrix();
    glFlush();
}

// special functionality
void cloudMoveDown(){
    cy = cy-0.001;
    if(cy < -15){
        cy = 15;
    }
    glutPostRedisplay();
}
void cloudMoveUp(){
    cy = cy+0.001;
    if(cy < 15){
        cy = -15;
    }
    glutPostRedisplay();
}
void cloudMoveLeft(){
    cx = cx-0.001;
    if(cx < -15){
        cx = 15;
    }
    glutPostRedisplay();
}
void cloudMoveRight(){
    cx = cx+0.001;
    if(cx < 15){
        cx = -15;
    }
    glutPostRedisplay();
}


void specialKey(int key, int x, int y){
    switch(key){
    case GLUT_KEY_DOWN:
        glutIdleFunc(cloudMoveDown);
        break;
    case GLUT_KEY_UP:
        glutIdleFunc(cloudMoveUp);
        break;
    case GLUT_KEY_LEFT:
        glutIdleFunc(cloudMoveLeft);
        break;
    case GLUT_KEY_RIGHT:
        glutIdleFunc(cloudMoveRight);
        break;

    default:
        break;
    }
}
void mouseMoveLeft(){
    cx = cx-0.001;
    if(cx < -15){
        cx = 15;
    }
    glutPostRedisplay();
}
void mouseMoveRight(){
    cx = cx+0.001;
    if(cx < 15){
        cx = -6;
    }
    glutPostRedisplay();
}

void mouseKey(int button, int state, int x , int y){
    switch(button){
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN){
            glutIdleFunc(mouseMoveLeft);
        }
        /*
        else if(state == GLUT_UP){
            glutIdleFunc(NULL);
            glutPostRedisplay();
        }
        */
        break;
        case GLUT_RIGHT_BUTTON:
        if(state == GLUT_UP){
            glutIdleFunc(mouseMoveRight);
        }
        /*
        else if(state == GLUT_DOWN){
            glutIdleFunc(NULL);
            glutPostRedisplay();
        }
        */
        break;
        default:
            break;
    }
}

void keyboardKey(unsigned char key, int x, int y){
    switch(key){
    case 'a':
        c1=cl1;
        c2=cl2;
        c3=cl3;
        glutPostRedisplay();
    break;
    case 'b':
        c1=c2=c3=1;
        glutPostRedisplay();
    break;

    default:
        break;
    }
}


int main(){
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600,600);
  glutInitWindowPosition(50,50);
  glutCreateWindow("PRACTISE");
  init();
  glutDisplayFunc(myDisplay);
  glutKeyboardFunc(keyboardKey);
  glutSpecialFunc(specialKey);
  glutMouseFunc(mouseKey);

  glutMainLoop();

  return 0;

}
