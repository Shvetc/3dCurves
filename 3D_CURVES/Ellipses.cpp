#include<Ellipses.h>
#include<assert.h>

Ellipses::Ellipses()
{
	_a = 0;
	_b = 0;
}

int Ellipses::get_class_id()
{
	return ellipse_id;
}

void Ellipses::set_radius(double a, double b)
{
	assert(a > 0 && b > 0);
	_a = a;
	_b = b;
}

Point Ellipses::get_point(const double t)
{

	Point p;
	p.x = _a * cos(t);
	p.y = _b * sin(t);
	p.z = 0;
	return p;
}

FirstDerivative Ellipses::get_derivative(const double t)
{
	FirstDerivative fd;
	fd.dx = (-1) * _a * sin(t);
	fd.dy = _b * cos(t);
	fd.dz = 0;
	return fd;
}