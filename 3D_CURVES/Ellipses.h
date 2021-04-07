#pragma once
#include<Curves.h>
#include<math.h>


class Ellipses : public GeometricCurves
{
public:
	double _a;
	double _b;
	Ellipses();
	int get_class_id();
	void set_radius(double a, double b);
	Point get_point(const double t);
	FirstDerivative get_derivative(const double t);
};