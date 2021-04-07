#pragma once
#include<Curves.h>
#include<math.h>
#include<assert.h>
class Dhelixes : public GeometricCurves
{
public:
	int _a, _b;
	
	Dhelixes();
	int get_class_id();
	void set_radius(int a, int b);
	Point get_point(const double t);
	FirstDerivative get_derivative(const double t);
};