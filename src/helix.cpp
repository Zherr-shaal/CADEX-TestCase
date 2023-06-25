
#include "helix.h"

Helix::Helix(double n_r, double n_h){
	r = abs(n_r);
	h = n_h;
}

Helix::~Helix(){
	
}

std::vector<double> Helix::getPoint(double t){
	std::vector<double> res;
	res.push_back(r*cos(t));
	res.push_back(r*sin(t));
	res.push_back(h*t);
	return res;
}

std::vector<double> Helix::getDerivative(double t){
	std::vector<double> res;
	res.push_back(-r*sin(t));
	res.push_back(r*cos(t));
	res.push_back(h);
	return res;
}
std::string Helix::toString(){

	return "Helix: r = " + std::to_string(r) + ", h = " + std::to_string(h);
}