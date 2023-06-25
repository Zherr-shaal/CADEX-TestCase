/*	
	There are three types of curves: circle, ellipse and helix
	Circle is defined by its radius
	Ellipse is defined by its radii for X and Y axis
	Helix is defined by its radius and step
	Parameter t is radian value
	Derivative coordinates computes by substitution of t in derivative from parametric equations.
*/
#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
#include <string>
class Curve {
	public:
		virtual ~Curve() {}
		virtual std::vector<double> getPoint(double t) = 0;
		virtual std::vector<double> getDerivative(double t) = 0;
		virtual std::string toString() = 0;
};