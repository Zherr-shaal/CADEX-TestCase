
#include "ellipse.h"

Ellipse::Ellipse(double n_rx, double n_ry){
	rx = abs(n_rx);
	ry = abs(n_ry);
}

Ellipse::~Ellipse(){
	
}

std::vector<double> Ellipse::getPoint(double t){
	std::vector<double> res;
	res.push_back(rx*cos(t));
	res.push_back(ry*sin(t));
	res.push_back(0.0d);
	return res;
}

std::vector<double> Ellipse::getDerivative(double t){
	std::vector<double> res;
	res.push_back(-rx*sin(t));
	res.push_back(ry*cos(t));
	res.push_back(0.0d);
	return res;
}
std::string Ellipse::toString(){
	return "Ellipse: rx = " + std::to_string(rx) + ", ry = " + std::to_string(ry);
}