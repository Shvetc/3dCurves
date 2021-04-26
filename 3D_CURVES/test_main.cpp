
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
	srand(time(nullptr));//the results of the program will be different from each other when time(NULL)
	int count = 0;
	int n = 14;
	int max_r = 5;//possible range of radius values of circels
	int max_a = 8;//possible range of radiuses values of Ellipses/3Dehelixes
	int max_b = 10;//possible range of radiuses value of Ellipses/3Dehelixes
	unsigned int summ_of_radius = 0;
	vector<unique_ptr<GeometricCurves>> vect_curve_ptr(n);
	for (int i = 0; i < n; i++)
	{
		unsigned int R = 1 + rand() % max_r;
		unsigned int a = 1 + rand() % max_a;
		unsigned int b = 1 + rand() % max_b;
		switch ((ClassId)(1 + rand() % 3))
		{
			case circle_id:
			{
				Circles* tmp = new Circles;
				assert(tmp != nullptr);
				vect_curve_ptr[i].reset(tmp);
				tmp->set_radius(R);
				count++;
				break;
			}
			case ellipse_id:
			{
				Ellipses* tmp = new Ellipses;
				assert(tmp != nullptr);
				vect_curve_ptr[i].reset(tmp);
				tmp->set_radiuses(a, b);
				break;
			}
			case helix_id:
			{
				Dhelixes* tmp = new Dhelixes;
				assert(tmp != nullptr);
				vect_curve_ptr[i].reset(tmp);
				tmp->set_radiuses(a, b);
				break;
			}
			default:
				assert(false);
		}
	}
	vector<unique_ptr<Circles>> vect_circles(count);
	assert(count == vect_circles.size());

	std::cout << "Print coordinates of points and derivatives of all curves in the container at t = PI/4 :" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "point: ";
		vect_curve_ptr[i]->get_point(M_PIl / 4).print();
		cout << "derivative: ";
		vect_curve_ptr[i]->get_derivative(M_PIl / 4).print();
		cout << "\n" << endl;
	}
	
	//Second container with circles
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		Circles* tmp = dynamic_cast<Circles*>(vect_curve_ptr[i].get());
		if (tmp != nullptr)
		{
			vect_circles[j++].reset(tmp);
		}
	}
	//Sort the second container in the ascending order of circles’ radii
	sort(vect_circles.begin(), vect_circles.end(),
		[](const unique_ptr<Circles>& a, const unique_ptr<Circles>& b) -> bool
		{
			return (a->get_r() < b->get_r());
		}
	);
	//Find summ
	for (int i = 0; i < vect_circles.size(); i++)
	{
		cout << "Radiuses of circles " << i + 1 << " = " << vect_circles[i]->get_r() << endl;
	}
	// parallel summ accumulation
#pragma omp parallel for reduction(+:summ_of_radius)
	for (int i = 0; i < vect_circles.size(); i++)
	{
		summ_of_radius += vect_circles[i]->get_r();
	}

	cout << "Summ of radiuses of circles = " << summ_of_radius << endl;

	return 0;
}