#pragma once
#include<iostream>

struct Point
{
	double x = 0;
	double y = 0;
	double z = 0;
	void print();
};

struct FirstDerivative
{
	double dx = 0;
	double dy = 0;
	double dz = 0;
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
	virtual Point  get_point(const double t) = 0;
	virtual FirstDerivative get_derivative(const double t) = 0;
	virtual int get_class_id();//{ return base_id; }
};
