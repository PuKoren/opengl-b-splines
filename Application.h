#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "maths/Vector2.h"
#include "config.h"

using namespace std;

class Application{
private:
	std::vector<Vector2> vectors;
public:
	Application();
	~Application();
	void keyboard(unsigned char key, int x, int y);
	void mouse(int button, int state, int x, int y);
	void run();
	void update();
	void draw();
};

#endif