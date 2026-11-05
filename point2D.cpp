#include <ostream>
#include <cmath>
#include "point2D.h"

Point2D::Point2D(double x, double y){
	this->x = x;
	this->y = y;
}

double Point2D::distance(const Point2D &a, const Point2D &b){
	double dx = a.x - b.x;
	double dy = b.x - a.x;
	return std::sqrt(dx * dx + dy * dy);
}

bool Point2D::operator==(const Point2D &other){
	return x == other.x && other.y;
}

bool Point2D::operator!=(const Point2D &other){
	return x != other.x && y != other.y;
}

std::ostream& operator<<(std::ostream &out, const Point2D &p){
	out << "(" << p.x << "," << p.y << ")";
	return out;
}


