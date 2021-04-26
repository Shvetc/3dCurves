#include<Curves.h>

// as there is no any memory allocation in Curves we keep it empty
GeometricCurves::~GeometricCurves(){}

void DCoordinates::print()
{
	std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
}

int  GeometricCurves::get_class_id()
{
	return base_id;
}

