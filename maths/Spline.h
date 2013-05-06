#ifndef _SPLINE_H
#define _SPLINE_H
#include <vector>
#include <GL/freeglut.h>
#include "Vector2.h"
#include "../config.h"

class Spline{
private:
	Vector2* splinePoints;
	void computeKnots(int *u,int n,int t);
	void computeCurve(Vector2 *inp,int nn,int *knots,int t);
	void computePoint(int *u,int n,int t,double v,Vector2 *control,Vector2 *output);
	double blendPoint(int k,int t,int *u,double v);
public:
	Spline();
	~Spline();
	void update(int degree, int n, Vector2*);
	void draw();
};

#endif