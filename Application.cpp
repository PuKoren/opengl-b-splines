#include "Application.h"

Application::Application(){

}

Application::~Application(){

}

void Application::keyboard(unsigned char key, int x, int y){
	switch (key){
		case '\x1B':
			glutLeaveMainLoop();
			break;
    }
}

void Application::mouse(int button, int state, int x, int y){
    if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
        this->vectors.push_back(Vector2(x, window_height - y - 5));
    }
}

void Application::run(){

}

void Application::update(){

}

void Application::draw(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
        //draw vectors
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            glBegin(GL_QUADS);
            glVertex2f(this->vectors[i].X, this->vectors[i].Y - 10);
            glVertex2f(this->vectors[i].X + 10, this->vectors[i].Y - 10);
            glVertex2f(this->vectors[i].X + 10, this->vectors[i].Y);
            glVertex2f(this->vectors[i].X, this->vectors[i].Y);
            glEnd();
        }

        //draw lines between vectors
        for(unsigned int i = 0; i < this->vectors.size()-1; i++){
            glBegin(GL_LINES);
            glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y - 5);
            glVertex2f(this->vectors[i+1].X + 5, this->vectors[i+1].Y - 5);
            glEnd();
        }
    glFlush();
}