
#include "circle.h"

Circle::Circle(double n_r){
	r = abs(n_r);
}

Circle::~Circle(){
	
}

std::vector<double> Circle::getPoint(double t){
	std::vector<double> res;
	res.push_back(r*cos(t));
	res.push_back(r*sin(t));
	res.push_back(0.0d);
	return res;
}

std::vector<double> Circle::getDerivative(double t){
	std::vector<double> res;
	res.push_back(-r*sin(t));
	res.push_back(r*cos(t));
	res.push_back(0.0d);
	return res;
}

double Circle::getR(){
	return r;
}

std::string Circle::toString(){
	return "Circle: r = " + std::to_string(r);
}