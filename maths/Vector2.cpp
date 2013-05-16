#include "Vector2.h"

Vector2::Vector2(Vector2 *v){
	this->X = v->X;
	this->Y = v->Y;
	this->Z = v->Z;
}
Vector2::Vector2(){
	this->X = 0;
	this->Y = 0;
	this->Z = 0;
}
Vector2::Vector2(const Vector2 &v){
	this->X = v.X;
	this->Y = v.Y;
	this->Z = v.Z;
}
Vector2::~Vector2(){

}
Vector2::Vector2(int x, int y){
	this->X = (float)x;
	this->Y = (float)y;
	this->Z = 0.f;
}

Vector2::Vector2(int x, int y, int z){
	this->X = (float)x;
	this->Y = (float)y;
	this->Z = (float)z;
}

Vector2::Vector2(float x, float y){
	this->X = x;
	this->Y = y;
	this->Z = 0.f;
}

Vector2::Vector2(float x, float y, float z){
	this->X = x;
	this->Y = y;
	this->Z = z;
}

/*
* Compute the Euclidian distance between two Vector2->
* Distance is sqrt((v1->X - v2->X)² + (v1->Y - v2->Y)²)
*/
int Vector2::Distance(Vector2 v){
	return (int)sqrt((float)(this->X - v.X)*(this->X - v.X) + (this->Y - v.Y) * (this->Y - v.Y));
}

/*
* Compute the length of a vector
* sqrt(x²+y²)
*/
float Vector2::Length(){
	return sqrt((float)(this->X*this->X + this->Y*this->Y));
}

/*
* Normalize a vector
* Vector2(X/Length, Y/Length)
*/
Vector2 Vector2::Normalize(){
	return Vector2(this->X/this->Length(), this->Y/this->Length());
}

void Vector2::RotateAround(Vector2 center, float angle){ 
	angle = angle * V_PI / 180;
	float x = this->X - center.X;
	float y = this->Y - center.Y;
	float cs = cos(angle);
	float sn = sin(angle);
	this->X = (x * cs - y * sn) + center.X;
	this->Y = (x * sn + y * cs) + center.Y;
}

Vector2 Vector2::operator-(Vector2 v){
	return Vector2(this->X - v.X, this->Y - v.Y);
}

Vector2 Vector2::operator+(Vector2 v){
	return Vector2(this->X + v.X, this->Y + v.Y);
}

Vector2 Vector2::operator+=(Vector2 v){
	return Vector2(this->X + v.X, this->Y + v.Y);
}

Vector2 Vector2::operator*(Vector2 v){
	return Vector2(this->X * v.X, this->Y * v.Y);
}

Vector2 Vector2::operator*(float f){
	return Vector2(this->X * f, this->Y * f);
}