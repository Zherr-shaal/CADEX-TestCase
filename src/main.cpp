/*
	Test task for CAD Exchanger
	Author: Zherebtsov Matvey
	Program implements support of 3D curves hierarchy.
*/
#include "main.h"

/*
	Second task: randomly generated vector
	Parameter size defines number of objects
	Random restricted by (1;100) to make easier manually checking.
*/
std::vector<std::shared_ptr<Curve>> generateVector(int size){
	std::vector<std::shared_ptr<Curve>> res;
	srand(time(NULL));
	for (int i = 0; i < size; i++){
		int t = rand() % 3;
		switch(t){
			case 0:
				res.push_back(std::make_shared<Circle>(Circle(rand()%100+1))); 
				break;
			case 1:
				res.push_back(std::make_shared<Ellipse>(Ellipse(rand()%100+1,rand()%100+1)));
				break;
			case 2:
				res.push_back(std::make_shared<Helix>(Helix(rand()%100+1, rand()%100+1)));
			default:
				break;
		}
	}	
	return res;
}

/*
	Feature for demonstration of tasks 2,4,5. Prints vector.
*/
void printVector(std::vector<std::shared_ptr<Curve>> v){
	for (int i = 0; i < v.size(); i++) {
		std::cout << i+1 << ". " << (*v[i]).toString() << std::endl;
	}
	std::cout << std::endl;
}

/*
	Third task: for all curves prints coordinates of points and derivatives from parameter t.
*/
void printPointsAndDerivativesAt(std::vector<std::shared_ptr<Curve>> v, double t){
	std::cout << "At t = " << t << ":" << std::endl;
	auto toStr {
		[] (std::vector<double> v){
			std::ostringstream oss;
			if (!v.empty()) {
				std::copy(v.begin(), v.end() - 1, std::ostream_iterator<double>(oss, ", "));
				oss << v.back();
			}
		return oss.str();
		}
	};
	for (int i = 0; i < v.size(); i++) {
		std::cout << i+1 << ". " << (*v[i]).toString() << std::endl;
		std::cout << "Point: " << toStr((*v[i]).getPoint(t)) << std::endl;
		std::cout << "Derivative: " << toStr((*v[i]).getDerivative(t)) << std::endl << std::endl;
	}
}

/*
	Fourth task: filters objects of Circle type to new vector.
	Feature use shared pointers: objects aren't cloned
*/
std::vector<std::shared_ptr<Curve>> filterCircles(std::vector<std::shared_ptr<Curve>> v){
	std::vector<std::shared_ptr<Curve>> res;
	for (auto curve : v){
		if (std::dynamic_pointer_cast<Circle>(curve)){
			std::cout << (*curve).toString() << std::endl;
			std::cout << "Address of first vector curve in memory: " << curve << std::endl;
			res.push_back(curve);
			std::cout << "Address of second vector curve in memory: " << res.back() << std::endl << std::endl;
		}
	}
	return res;
}

/*
	Fifth task: sorts filtered vector in ascending order 
*/
void sortVector(std::vector<std::shared_ptr<Curve>> v){
	std::sort(v.begin(), v.end(), [] (std::shared_ptr<Curve> curve1, std::shared_ptr<Curve> curve2) {
		std::shared_ptr<Circle> c1 = std::dynamic_pointer_cast<Circle>(curve1);
		std::shared_ptr<Circle> c2 = std::dynamic_pointer_cast<Circle>(curve2);
		return (*c1).getR() < (*c2).getR();
	});
}

/*
	Sixth task: computes sum of radii of all circles. It works on original vector as on filtered one 
*/
double sumOfCircleRadii(std::vector<std::shared_ptr<Curve>> v){
	double sum = 0;
	for (auto curve : v){
		if (std::dynamic_pointer_cast<Circle>(curve)){
			sum += (*std::dynamic_pointer_cast<Circle>(curve)).getR();
		}
	}
	return sum;
}
int main() {
	std::vector<std::shared_ptr<Curve>> v1 = generateVector(1000);
	printVector(v1);
	printPointsAndDerivativesAt(v1, M_PI/4);
	std::vector<std::shared_ptr<Curve>> v2 = filterCircles(v1);
	printVector(v2);
	sortVector(v2);
	printVector(v2);
	std::cout << "Total sum of radii: " << sumOfCircleRadii(v2) << std::endl;
	return 0;
}