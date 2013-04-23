#include <GL/freeglut.h>
#include "Application.h"
#include "config.h"

void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void display(void);
void update();

Application a;
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(window_width,window_height);
    glutCreateWindow("BSplines - OpenGL");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, window_width, 0, window_height); 
    
    glutKeyboardFunc(&keyboard);
    glutMouseFunc(&mouse);
    glutIdleFunc(&update);
    glutDisplayFunc(&display);
    glutMainLoop();
    glutExit();
    return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y){
    a.keyboard(key, x, y);
}

void mouse(int button, int state, int x, int y){
    a.mouse(button, state, x, y);
}

void update(){
    a.update();
}

void display(){
    a.draw();
}
