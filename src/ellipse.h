#pragma once
#include "curve.h"
/*
	Ellipse is represented by parametric function:
	x(t) = rx * cos(t)
	y(t) = ry * sin(t)
	z(t) = 0 (because ellipse is planar)
	Coordinates of derivative computes by:
	x'(t) = -rx * sin(t)
	y'(t) = ry * cos(t)
	z'(t) = 0 (because z is const)
*/
class Ellipse: public Curve {
	public:
		Ellipse(double n_rx, double n_ry);
		~Ellipse();
		
		std::vector<double> getPoint(double t);
		std::vector<double> getDerivative(double t);
		std::string toString();
	
	private:
		double rx;
		double ry;
};