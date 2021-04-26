#pragma once
#include<Curves.h>
#include<math.h>
#include<assert.h>

class Circles : public GeometricCurves
{
	unsigned int _r;
public:
	Circles();
	~Circles() override;
	double get_r();
	int get_class_id();
	void set_radius(unsigned int r);
	DCoordinates get_point(const double t);
	DCoordinates get_derivative(const double t);
};