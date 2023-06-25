#pragma once
#include "curve.h"
/*
	Circle is represented by parametric function:
	x(t) = r * cos(t)
	y(t) = r * sin(t)
	z(t) = 0 (because circle is planar)
	Coordinates of derivative computes by:
	x'(t) = -r * sin(t)
	y'(t) = r * cos(t)
	z'(t) = 0 (because z is const)
*/
class Circle: public Curve {
	public:
		Circle(double n_r);
		~Circle();
		
		std::vector<double> getPoint(double t);
		std::vector<double> getDerivative(double t);
		double getR();
		std::string toString();
		
	
	private:
		double r;
};