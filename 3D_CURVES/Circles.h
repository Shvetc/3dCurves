#pragma once
#include<Curves.h>
#include<math.h>
#include<assert.h>

class Circles : public GeometricCurves
{
public:
	double _r;

	Circles();
	double get_r();
	int get_class_id();
	void set_radius(double r);
	Point get_point(const double t);
	FirstDerivative get_derivative(const double t);
};