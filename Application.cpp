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
        Vector2 clickedVector = Vector2(x, window_height - y);

        int selected = -1;
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            if(clickedVector.Distance(&this->vectors[i]) < 10.0f){
                selected = i;
            }
        }

        if(selected < 0){
            this->vectors.push_back(clickedVector);
            if(this->vectors.size() > 1){
                this->spline.update(3, this->vectors.size(), &this->vectors[0]);
            }
        }
    }
}

void Application::run(){

}

void Application::update(){
    
}

void Application::draw(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f, 0.5f, 0.5f);
        //draw vectors
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            glBegin(GL_QUADS);
            glVertex2f(this->vectors[i].X - 5, this->vectors[i].Y - 5);
            glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y - 5);
            glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y + 5);
            glVertex2f(this->vectors[i].X - 5, this->vectors[i].Y + 5);
            glEnd();
        }

        this->spline.draw();

    glFlush();
}
