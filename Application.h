#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <vector>
#include <GL/freeglut.h>
#include "maths/Vector2.h"
#include "maths/Spline.h"
#include "config.h"

using namespace std;

class Application{
private:
	std::vector<Vector2> vectors;
	Spline spline;
	int selected;
	int degree;
	bool rotate;
	bool drawLines;
	Vector2 latestMousePosition;
	Vector2 rotationAxis;
public:
	Application();
	~Application();
	void keyboard(unsigned char key);
	void keyboardSpecial(int key);
	void mouse(int button, int state, int x, int y);
	void mouseMotion(int x, int y);
	void draw();
	void update();
	int getDegree();
};

#endif
