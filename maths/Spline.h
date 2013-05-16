#ifndef _SPLINE_H
#define _SPLINE_H
#include <vector>
#include <GL/freeglut.h>
#include "Vector2.h"
#include "../config.h"

class Spline{
private:
	Vector2* splinePoints;
	void computeKnots(int*,int,int);
	void computeCurve(Vector2*,int,int*,int);
	Vector2 computePoint(int*,int,int,double,Vector2*);
	double blendPoint(int,int,int*,double);
public:
	Spline();
	~Spline();
	void update(int,int,Vector2*);
	void draw();
};

#endif