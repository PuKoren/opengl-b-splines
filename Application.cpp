#include "Application.h"
//#include <iostream>

Application::Application(){
    this->selected = -1;
    this->degree = 3;
    this->rotate = false;
    this->move = false;
    this->drawLines = true;
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
            this->rotate = !this->rotate;
            this->rotationAxis = this->latestMousePosition;
            this->update();
            break;
        case 32:
            this->drawLines = !this->drawLines;
            glutPostRedisplay();
            break;
        case 26:
            if(this->vectors.size() > 0){
                this->vectors.erase(this->vectors.begin() + this->vectors.size());
                this->update();
            }
            break;
        case 127:
            this->vectors.clear();
            this->rotate = false;
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
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            if(this->latestMousePosition.Distance(&this->vectors[i]) < 10.0f){
                this->selected = i;
                glutPostRedisplay();
            }
        }

        if(selected < 0){
            this->vectors.push_back(this->latestMousePosition);
            this->selected = this->vectors.size()-1;
            if(this->vectors.size() > 1){
                this->update();
            }
        }
    }else if(this->selected < 0 && state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON){
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            if(this->latestMousePosition.Distance(&this->vectors[i]) < 10.0f){
                this->vectors.erase(this->vectors.begin()+i);
                this->update();
                break;
            }
        }
    }else if(this->selected < 0 && state == GLUT_DOWN && button == GLUT_MIDDLE_BUTTON){
        this->move = true;
    }

    if(state == GLUT_UP){
        if(button == GLUT_MIDDLE_BUTTON){
            this->move = false;
        }
        this->selected = -1;
        glutPostRedisplay();
    }
}

void Application::mouseMotion(int x, int y){
    if(this->selected > -1){
        Vector2 clickedVector = Vector2(x, window_height - y);
        this->vectors[this->selected] = clickedVector;
        this->update();
    }
    if(this->move){
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            this->vectors[i].X += x - this->latestMousePosition.X;
            this->vectors[i].Y += (window_height - y) - this->latestMousePosition.Y;
        }
        this->update();
    }
    this->latestMousePosition.X = x;
    this->latestMousePosition.Y = window_height - y;
}

void Application::draw(){
    if(this->rotate){
        for(unsigned int i = 0; i < this->vectors.size(); i++){
            this->vectors[i].RotateAround(this->rotationAxis, 2.5f);
        }
        this->update();
    }
    glColor3ub(255, 107, 107);
    //draw vectors
    for(unsigned int i = 0; i < this->vectors.size(); i++){
        //highlight current selected control point
        if(i == this->selected){
            glColor3ub(199, 244, 100);
        }
        glBegin(GL_QUADS);
        glVertex2f(this->vectors[i].X - 5, this->vectors[i].Y - 5);
        glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y - 5);
        glVertex2f(this->vectors[i].X + 5, this->vectors[i].Y + 5);
        glVertex2f(this->vectors[i].X - 5, this->vectors[i].Y + 5);
        glEnd();

        //put back old color
        if(i == this->selected){
            glColor3ub(255, 107, 107);
        }
    }

    //draw lines between vectors
    if(this->drawLines && this->vectors.size() > 0){
        for(unsigned int i = 0; i < this->vectors.size() -1; i++){
            glBegin(GL_LINES);
            glVertex2f(this->vectors[i].X, this->vectors[i].Y);
            glVertex2f(this->vectors[i+1].X, this->vectors[i+1].Y);
            glEnd();
        }
    }

    glColor3ub(199, 244, 100);
    //draw spline
    this->spline.draw();
}

int Application::getDegree(){
    return this->degree;
}
