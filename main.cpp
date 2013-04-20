#include <GL/freeglut.h>

void keyboard(unsigned char key, int x, int y);
void display(void);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    int windowID = glutCreateWindow("BSplines - OpenGL");
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);
    glutMainLoop();
    glutDestroyWindow(windowID);
    glutExit();
    return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case '\x1B':
            exit(EXIT_SUCCESS);
            break;
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();
}
