#pragma once
#include "curve.h"
/*
	Helix is represented by parametric function:
	x(t) = r * cos(t)
	y(t) = r * sin(t)
	z(t) = h * t
	Coordinates of derivative computes by:
	x'(t) = -r * sin(t)
	y'(t) = r * cos(t)
	z'(t) = h
*/
class Helix: public Curve {
	public:
		Helix(double n_r, double n_ry);
		~Helix();
		
		std::vector<double> getPoint(double t);
		std::vector<double> getDerivative(double t);
		std::string toString();
	
	private:
		double r;
		double h;
};