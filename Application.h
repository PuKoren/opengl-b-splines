#ifndef _APPLICATION_H
#define _APPLICATION_H
#include <GL/freeglut.h>

class Application{
private:

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