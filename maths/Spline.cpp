#include "Spline.h"

Spline::Spline(){
    this->splinePoints = new Vector2[window_width];
}

Spline::~Spline(){
    delete[] splinePoints;
}

//recursive function to compute the blend value
double Spline::blendPoint(int i,int degree,int* knots,double index){
    double value;
    if (degree == 1) {
        if ((knots[i] <= index) && (index < knots[i+1])){
            value = 1;
        }else{
            value = 0;
        }
    } else {
        if (knots[i + degree - 1] == knots[i] && knots[i + degree] == knots[i+1]){
            value = 0;
        }else if (knots[i + degree - 1] == knots[i]){
            value = (knots[i + degree] - index) / (knots[i + degree] - knots[i + 1]) * blendPoint(i + 1,degree - 1,knots,index);
        }else if (knots[i + degree] == knots[i + 1]){
            value = (index - knots[i]) / (knots[i + degree - 1] - knots[i]) * blendPoint(i,degree - 1,knots,index);
        }else{
            value = (index - knots[i]) / (knots[i + degree - 1] - knots[i]) * blendPoint(i,degree - 1,knots,index) +
                (knots[i + degree] - index) / (knots[i + degree] - knots[i + 1]) * blendPoint(i + 1,degree - 1,knots,index);
        }
    }

    return(value);
}

//compute a single point of the spline
Vector2 Spline::computePoint(int *knots,int count,int degree,double index,Vector2 *control){
    Vector2 output;
    for (int i = 0; i <= count; i++) {
        double b = blendPoint(i,degree,knots,index);
        output.X += control[i].X * b;
        output.Y += control[i].Y * b;
        output.Z += control[i].Z * b;
    }
    return output;
}

//this creates all the points along the curve
void Spline::computeCurve(Vector2* controls, int CPcount,int *knots,int Kcount){
    double interval,increment;
    interval = 0;
    increment = (CPcount - Kcount + 2) / (double)(window_width - 1);
    for (int i = 0; i < window_width - 1; i++) {
        this->splinePoints[i] = computePoint(knots,CPcount,Kcount,interval,controls);
        interval += increment;
    }
}

//put knots in first parameter
void Spline::computeKnots(int* knots,int count,int degree){
    for (int i = 0; i <= count+degree; i++) {
        if (i < degree){
            knots[i] = 0;
        }else if (i <= count){
            knots[i] = i - degree + 1;
        }else if (i > count){
            knots[i] = count - degree + 2;
        }
    }
}


void Spline::update(int degree, int count, Vector2* controlPoints){
    int* u = new int[count + degree + 1];
    this->computeKnots(u, count-1, degree);
    this->computeCurve(controlPoints, count-1, u, degree);
    delete[] u;
}

void Spline::draw(){
    for(unsigned int i = 0; i < window_width-1; i++){
        if(splinePoints[i+1].X == 0 && splinePoints[i+1].Y == 0){
            break;
        }
        glBegin(GL_LINES);
        glVertex2f(splinePoints[i].X, splinePoints[i].Y);
        glVertex2f(splinePoints[i+1].X, splinePoints[i+1].Y);
        glEnd();
    }
}