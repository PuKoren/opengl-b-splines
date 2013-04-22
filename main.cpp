#include <GL/freeglut.h>
#include "Application.h"

void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void display(void);
void update();

Application a;
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("BSplines - OpenGL");
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
