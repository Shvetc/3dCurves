#include"Circles.h"

Circles::Circles()
{
	_r = 0;
}

// as there is no any memory allocation in Curves we keep it empty
Circles::~Circles(){}

double Circles::get_r()
{
	return _r;;
}
int Circles::get_class_id()
{
	return circle_id;
}
void Circles::set_radius(unsigned int r)
{
	assert(r > 0); // This method should return  failed status. Assertion is prototype
	_r = r;
}
DCoordinates Circles::get_point(const double t)
{
	DCoordinates p;
	p.x = _r * cos(t);
	p.y = _r * sin(t);
	p.z = 0;
	return p;

}
DCoordinates Circles::get_derivative(const double t)
{
	DCoordinates fd;
	fd.x = (-1) * _r * sin(t);
	fd.y = _r * cos(t);
	fd.z = 0.0;
	return fd;
}


