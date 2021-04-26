#pragma once
#include<iostream>

struct DCoordinates
{
	double x = 0;
	double y = 0;
	double z = 0;
	void print();
};

enum ClassId
{
	base_id,
	circle_id,
	ellipse_id,
	helix_id
};

class GeometricCurves {

public:
	virtual ~GeometricCurves();
	virtual DCoordinates  get_point(const double t) = 0;
	virtual DCoordinates get_derivative(const double t) = 0;
	virtual int get_class_id();
};
