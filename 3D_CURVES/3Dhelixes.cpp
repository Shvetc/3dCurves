#include<3Dhelixes.h>

Dhelixes::Dhelixes()
{
	_a = 0;
	_b = 0;
}
// as there is no any memory allocation in Curves we keep it empty
Dhelixes::~Dhelixes(){}

int Dhelixes::get_class_id()
{
	return helix_id;
}
void Dhelixes::set_radiuses(unsigned int a, unsigned int b)
{
	assert(a > 0 && b > 0);
	_a = a;
	_b = b;
}
DCoordinates Dhelixes::get_point(const double t)
{
	DCoordinates p;
	p.x = _a * t * cos(t);
	p.y = _a * t * sin(t);
	p.z = _b * t;
	return p;
}
DCoordinates Dhelixes::get_derivative(const double t)
{
	DCoordinates fd;
	fd.x = _a * cos(t) + _a * t * -1 * sin(t);
	fd.y = _a * sin(t) + _a * t * cos(t);
	fd.z = _b;
	return fd;
}