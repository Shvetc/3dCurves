
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include <time.h> 
#include<vector>
#include <cmath>
#include<iostream>
#include<Curves.h>
#include<Circles.h>
#include<Ellipses.h>
#include<3Dhelixes.h>
#include <algorithm>
#include <omp.h>
#include <assert.h>
#define _USE_MATH_DEFINES
using namespace std;
# define M_PIl 3.141592653589793238462643383279502884L 
int main()
{
	srand(777);
	int count = 0;
	int n = 10; 
	int j = 0;

	double summ_of_radius = 0;
	vector<unique_ptr<GeometricCurves>> vect_curve_ptr(n);
	for (int i = 0; i < n; i++)
	{
		switch ((ClassId)(1 + rand() % 3))
		{
			case circle_id:
			{
				Circles* tmp = new Circles;
				vect_curve_ptr[i].reset(tmp);
				count++;
				break;
			}
			case ellipse_id:
			{
				Ellipses* tmp = new Ellipses;
				vect_curve_ptr[i].reset(tmp);
				break;
			}
			case helix_id:
			{
				Dhelixes* tmp = new Dhelixes;
				vect_curve_ptr[i].reset(tmp);
				break;
			}
			default:
				assert(false);
		}
	}
	vector<Circles*> vect_circles(count);
	assert(count == vect_circles.size());
	for (int i = 0; i < n; i++)
	{
		double R = 1 + rand() % 5;
		double a = 1 + rand() % 8;
		double b = 1 + rand() % 10;
		switch (vect_curve_ptr[i]->get_class_id())
		{
			case circle_id:
			{	
			
				Circles* tmp1 = dynamic_cast<Circles*>(vect_curve_ptr[i].get());
				assert(tmp1 != nullptr);
				tmp1->set_radius(R);
				break;
			}

			case ellipse_id:
			{
				Ellipses* tmp2 = dynamic_cast<Ellipses*>(vect_curve_ptr[i].get());
				assert(tmp2 != nullptr);
				tmp2->set_radius(a, b);
				break;
			}

			case helix_id:
			{
				Dhelixes* tmp3 = dynamic_cast<Dhelixes*>(vect_curve_ptr[i].get());
				assert(tmp3 != nullptr);
				tmp3->set_radius(a,b);
				break;
			}
			default:
				assert(false);
		}
	}
	
	std::cout << "Print coordinates of points and derivatives of all curves in the container at t=PI/4 :" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "point: ";
		vect_curve_ptr[i]->get_point(M_PIl / 4).print();
		cout << "derivative: ";
		vect_curve_ptr[i]->get_derivative(M_PIl / 4).print();
	}
	
	//Second container with circles
	for (int i = 0; i < n; i++)
	{
		Circles* tmp = dynamic_cast<Circles*>(vect_curve_ptr[i].get());
		if (tmp != nullptr)
		{
			vect_circles[j++] = tmp;
		}
	}
	//Sort the second container in the ascending order of circles’ radii
	sort(vect_circles.begin(), vect_circles.end(),
		[](Circles* a, Circles* b)
		{
			return (a->get_r() < b->get_r());
		}
	);
	//Find summ
#pragma omp parallel for reduction(+:summ_of_radius)
	for (int i = 0; i < vect_circles.size(); i++)
	{
		summ_of_radius += vect_circles[i]->get_r();
	}

	cout << "Summ of radiuses of circles = " << summ_of_radius << endl;

	return 0;
}