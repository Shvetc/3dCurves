#pragma once
#include<Curves.h>
#include<math.h>


class Ellipses : public GeometricCurves
{
	unsigned int _a;
	unsigned int _b;
public:
	Ellipses();
	~Ellipses() override;
	int get_class_id();
	void set_radiuses(unsigned int  a, unsigned int b);
	DCoordinates get_point(const double t);
	DCoordinates get_derivative(const double t);
};