#include "Application.h"

Application::Application(){
    this->selected = -1;
    this->degree = 4;
}

Application::~Application(){

}

void Application::keyboard(unsigned char key){
	switch (key){
		case '\x1B':
			glutLeaveMainLoop();
			break;
        case '\x2B':
            if(this->degree < 6){
                this->degree ++;
                this->update();
            }
            break;
        case '\x2D':
            if(this->degree > 2){
                this->degree --;
                this->update();
            }
            break;
        case '\x72':
            this->vectors[0].Z -= 1.f;
            this->update();
            break;
    }
}
void Application::keyboardSpecial(int key){
    switch (key){
        case GLUT_KEY_RIGHT:
            for(unsigned int i = 0; i < this->vectors.size(); i++){
                this->vectors[i].X += 5;
            }
            break;
        case GLUT_KEY_LEFT:
            for(unsigned int i = 0; i < this->vectors.size(); i++){
                this->vectors[i].X -= 5;
            }
            break;
        case GLUT_KEY_UP:
            for(unsigned int i = 0; i < this->vectors.size(); i++){
                this->vectors[i].Y += 5;
            }
            break;
        case GLUT_KEY_DOWN:
            for(unsigned int i = 0; i < this->vectors.size(); i++){
                this->vectors[i].Y -= 5;
            }
            break;
    }
    this->update();
}

void Application::update(){
    this->spline.update(this->degree, this->vectors.size(), &this->vectors[0]);
    glutPostRedisplay();
}

void Application::mouse(int button, int state, int x, int y){
    if(this->selected < 0 && state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
        Vector2 clickedVector = Vector2(x, window_height - y);
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            if(clickedVector.Distance(&this->vectors[i]) < 10.0f){
                this->selected = i;
            }
        }

        if(selected < 0){
            this->vectors.push_back(clickedVector);
            if(this->vectors.size() > 1){
                this->update();
            }
        }
    }
    if(state == GLUT_UP){
        selected = -1;
    }
}

void Application::mouseMotion(int x, int y){
    if(this->selected > -1){
        Vector2 clickedVector = Vector2(x, window_height - y);
        this->vectors[this->selected] = clickedVector;
        this->update();
    }
}

void Application::draw(){
    glColor3f(0.0f, 0.5f, 0.5f);
    //draw vectors
    for(unsigned int i = 0; i < this->vectors.size(); i++){
        glBegin(GL_QUADS);
        glVertex2f(this->vectors[i].X - 5, this->vectors[i].Y - 5);
        glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y - 5);
        glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y + 5);
        glVertex2f(this->vectors[i].X - 5, this->vectors[i].Y + 5);
        glEnd();
    }

    //draw lines between vectors
    if(this->vectors.size() > 0){
        for(unsigned int i = 0; i < this->vectors.size() -1; i++){
            glBegin(GL_LINES);
            glVertex2f(this->vectors[i].X, this->vectors[i].Y);
            glVertex2f(this->vectors[i+1].X, this->vectors[i+1].Y);
            glEnd();
        }
    }

    glColor3f(0.5f, 0.0f, 0.5f);
    //draw spline
    this->spline.draw();
}

int Application::getDegree(){
    return this->degree;
}
