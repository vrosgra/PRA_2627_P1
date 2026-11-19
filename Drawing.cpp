#include "Drawing.h"
#include "ListArray.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
    }
}

double Drawing::get_area_all_circles() {
    double total = 0;
    for (int i = 0; i < shapes->size(); i++) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c != nullptr) {
            total += c->area();
        }
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Square* s = dynamic_cast<Square*>(shapes->get(i));
        if (s != nullptr) {
            s->translate(incX, incY);
        }
    }
}
