#include<Ellipses.h>
#include<assert.h>

Ellipses::Ellipses()
{
	_a = 0;
	_b = 0;
}

// as there is no any memory allocation in Curves we keep it empty
Ellipses::~Ellipses(){}

int Ellipses::get_class_id()
{
	return ellipse_id;
}

void Ellipses::set_radiuses(unsigned int a, unsigned int b)
{
	assert(a > 0 && b > 0);
	_a = a;
	_b = b;
}

DCoordinates Ellipses::get_point(const double t)
{

	DCoordinates p;
	p.x = _a * cos(t);
	p.y = _b * sin(t);
	p.z = 0;
	return p;
}

DCoordinates Ellipses::get_derivative(const double t)
{
	DCoordinates fd;
	fd.x = (-1) * _a * sin(t);
	fd.y = _b * cos(t);
	fd.z = 0;
	return fd;
}