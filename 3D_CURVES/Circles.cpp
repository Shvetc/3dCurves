#include"Circles.h"

Circles::Circles()
{
	_r = 0;
}

double Circles::get_r()
{
	return _r;;
}
int Circles::get_class_id()
{
	return circle_id;
}
void Circles::set_radius(double r)
{
	assert(r > 0); // This method should return  failed status. Assertion is prototype
	_r = r;
}
Point Circles::get_point(const double t)
{
	Point p;
	p.x = _r * cos(t);
	p.y = _r * sin(t);
	p.z = 0;
	return p;

}
FirstDerivative Circles::get_derivative(const double t)
{
	FirstDerivative fd;
	fd.dx = (-1) * _r * sin(t);
	fd.dy = _r * cos(t);
	fd.dz = 0.0;
	return fd;
}



