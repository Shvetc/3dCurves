#include<3Dhelixes.h>

Dhelixes::Dhelixes()
{
	_a = 0;
	_b = 0;
}
int Dhelixes::get_class_id()
{
	return helix_id;
}
void Dhelixes::set_radius(int a, int b)
{
	assert(a > 0 && b > 0);
	_a = a;
	_b = b;
}
Point Dhelixes::get_point(const double t)
{
	Point p;
	p.x = _a * t * cos(t);
	p.y = _a * t * sin(t);
	p.z = _b * t;
	return p;
}
FirstDerivative Dhelixes::get_derivative(const double t)
{
	FirstDerivative fd;
	fd.dx = _a * cos(t) + _a * t * -1 * sin(t);
	fd.dy = _a * sin(t) + _a * t * cos(t);
	fd.dz = _b;
	return fd;
}