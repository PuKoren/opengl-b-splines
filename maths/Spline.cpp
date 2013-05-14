#include "Spline.h"

Spline::Spline(){
	this->splinePoints = new Vector2[window_width];
}

Spline::~Spline(){
	delete[] splinePoints;
}

double Spline::blendPoint(int k,int t,int *u,double v)
{
  double value;

  if (t == 1) {
    if ((u[k] <= v) && (v < u[k+1]))
      value = 1;
    else
      value = 0;
  } else {
    if ((u[k+t-1] == u[k]) && (u[k+t] == u[k+1]))
      value = 0;
    else if (u[k+t-1] == u[k])
      value = (u[k+t] - v) / (u[k+t] - u[k+1]) * blendPoint(k+1,t-1,u,v);
    else if (u[k+t] == u[k+1])
      value = (v - u[k]) / (u[k+t-1] - u[k]) * blendPoint(k,t-1,u,v);
    else
      value = (v - u[k]) / (u[k+t-1] - u[k]) * blendPoint(k,t-1,u,v) +
              (u[k+t] - v) / (u[k+t] - u[k+1]) * blendPoint(k+1,t-1,u,v);
  }

  return(value);
}

void Spline::computePoint(int *u,int n,int t,double v,Vector2 *control,Vector2 *output)
{
  int k;
  double b;

  output->X = 0;
  output->Y = 0;

  for (k=0;k<=n;k++) {
    b = blendPoint(k,t,u,v);
    output->X += control[k].X * b;
    output->Y += control[k].Y * b;
    output->Z += control[k].Z * b;
  }
}

void Spline::computeCurve(Vector2 *inp,int nn,int *knots,int t)
{
   int i;
   double interval,increment;

   interval = 0;
   increment = (nn - t + 2) / (double)(window_width - 1);
   for (i=0;i<window_width-1;i++) {
      computePoint(knots,nn,t,interval,inp,&(this->splinePoints[i]));
      interval += increment;
   }
}

void Spline::computeKnots(int *u,int n,int t)
{
  int j;

  for (j=0;j<=n+t;j++) {
    if (j < t)
      u[j] = 0;
    else if (j <= n)
      u[j] = j - t + 1;
    else if (j > n)
      u[j] = n - t + 2;
  }
}


void Spline::update(int degree, int n, Vector2* controlPoints){
    int* u = new int[n + degree + 1];
    this->computeKnots(u, n-1, degree);
    this->computeCurve(controlPoints, n-1, u, degree);
    delete[] u;
}

void Spline::draw(){
	for(unsigned int i = 0; i < window_width-1; i++){
		if(splinePoints[i+1].X == 0 && splinePoints[i+1].Y == 0)
			break;
		glBegin(GL_LINES);
		glVertex2f(splinePoints[i].X, splinePoints[i].Y);
		glVertex2f(splinePoints[i+1].X, splinePoints[i+1].Y);
		glEnd();
	}
}