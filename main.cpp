#include <stdio.h>
#include <GL/freeglut.h>
#include "Application.h"
#include "config.h"

void displayText(float x, float y, int r, int g, int b, const char *string);
void keyboard(unsigned char key, int x, int y);
void keyboardSpecialKeys(int key, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void mousePassiveMotion(int x, int y);
void display();
void resize(int width, int height);

Application a;
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(window_width,window_height);
    glutCreateWindow("BSplines - OpenGL");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, window_width, 0, window_height); 
    
    glutKeyboardFunc(&keyboard);
    glutSpecialFunc(&keyboardSpecialKeys);
    glutMouseFunc(&mouse);
    glutMotionFunc(&mouseMotion);
    glutPassiveMotionFunc(&mousePassiveMotion);
    glutDisplayFunc(&display);
    glutReshapeFunc(&resize);
    glutMainLoop();
    glutExit();
    return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y){
    a.keyboard(key);
}

void keyboardSpecialKeys(int key, int x, int y){
    a.keyboardSpecial(key);
}

void mouse(int button, int state, int x, int y){
    a.mouse(button, state, x, y);
}

void mouseMotion(int x, int y){
    a.mouseMotion(x, y);
}

void mousePassiveMotion(int x, int y){
    a.mouseMotion(x, y);
}

void displayText(float x, float y, int r, int g, int b, const char *string) {
    int j = strlen( string );
    glColor3ub(r, g, b);
    glRasterPos2f(x, window_height - y - 13);
    for( int i = 0; i < j; i++ ) {
        glutBitmapCharacter( GLUT_BITMAP_8_BY_13, string[i] );
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    a.draw();
    displayText(0, 0, 78, 205, 196, "Welcome to the B-Spline drawer !");
    displayText(0, 10, 78, 205, 196, "Use left mouse button to place control points and move them");
    displayText(0, 20, 78, 205, 196, "Use right mouse button to delete a control point");
    displayText(0, 30, 78, 205, 196, "Use + and - keys to change Spline Degree");
    displayText(0, 40, 78, 205, 196, "Use arrows to move every control points");
    displayText(0, 50, 78, 205, 196, "Use R key to rotate around your current mouse position (R to start, R to stop)");

    char notice[50];
    sprintf(notice, "Current degree: %d", a.getDegree());
    displayText(0, window_height/2, 199, 244, 100, notice);
    
    glutSwapBuffers();
}

void resize(int width, int height)
{
    window_width = width;
    window_height = height;
    glViewport(0, 0, window_width, window_height);
}