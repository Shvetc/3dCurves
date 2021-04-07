#include<Curves.h>

void Point::print()
{
	std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
}

void FirstDerivative::print()
{
	std::cout << "(" << dx << "," << dy << "," << dz << ")" << std::endl;
}

int  GeometricCurves::get_class_id()
{
	return base_id;
}

