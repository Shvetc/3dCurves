#pragma once
#include<Curves.h>
#include<math.h>
#include<assert.h>
class Dhelixes : public GeometricCurves
{
	unsigned int _a, _b;
public:
	Dhelixes();
	~Dhelixes() override;
	int get_class_id();
	void set_radiuses(unsigned int a, unsigned int b);
	DCoordinates get_point(const double t);
	DCoordinates get_derivative(const double t);
};