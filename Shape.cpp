#include "Shape.h"
#include <stdexcept>
#include <string>

using namespace std;

static bool color_valido(const string &c) {
	return c == "red" || c == "green" || c == "blue";
}

Shape::Shape() : color("red") {}

Shape::Shape(string color) {
	if (!color_valido(color)) {
		throw invalid_argument("Color no valido: debe ser red, green o blue");
	}
	this->color = color;
}

string Shape::get_color() const{
	return color;
}

void Shape::set_color(string c){
	if (!color_valido(c)) {
		throw invalid_argument("Color no valido: debe ser red, green o blue");
	}
	this->color = c;
}
