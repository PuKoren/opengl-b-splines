#include "Application.h"

Application::Application(){

}

Application::~Application(){

}

void Application::keyboard(unsigned char key, int x, int y){
	switch (key)
    {
		case '\x1B':
			exit(EXIT_SUCCESS);
			break;
    }
}

void Application::mouse(int button, int state, int x, int y){

}

void Application::run(){

}

void Application::update(){

}

void Application::draw(){
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.0f, 0.5f);
    glEnd();

    glFlush();
}