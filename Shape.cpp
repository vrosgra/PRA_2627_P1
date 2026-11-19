#include "Shape.h"
#include <stdexcept>
#include <string>

using namespace std;

Shape::Shape() : color("red") {}

Shape::Shape(string color) : color{color} {}

string Shape::get_color() const{
	return color;
}

void Shape::set_color(string c){
	this->color = c;
}

