#ifndef _VECTOR2_H
#define _VECTOR2_H
#include <cmath>
#define V_PI  3.14159265358979323846

class Vector2{
	public:
		Vector2();
		Vector2(Vector2 *);
		Vector2(const Vector2&);
		Vector2(float, float);
		Vector2(float, float, float);
		Vector2(int, int);
		Vector2(int, int, int);
		~Vector2();
		
		float X;
		float Y;
		float Z;

		int Distance(Vector2);
		float Length();
		Vector2 Normalize();
		void RotateAround(Vector2, float);
		Vector2 operator- (Vector2);
		Vector2 operator+ (Vector2);
		Vector2 operator+= (Vector2);
		Vector2 operator* (Vector2);
		Vector2 operator* (float);
};
#endif