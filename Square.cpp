#include <cmath>
#include <stdexcept>
#include "Square.h"

static bool almost_equal(double a, double b) {
    return std::fabs(a - b) < 1e-9;
}

bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    return almost_equal(d01, d12) && almost_equal(d12, d23) && almost_equal(d23, d30);
}

Square::Square() : Rectangle() {
    Point2D v[N_VERTICES] = { Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1) };
    set_vertices(v);
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    Rectangle::set_vertices(vertices);
}

std::ostream& operator<<(std::ostream &out, const Square &s) {
    out << "[Square: color = " << s.get_color()
        << "; v0 = " << s.get_vertex(0)
        << "; v1 = " << s.get_vertex(1)
        << "; v2 = " << s.get_vertex(2)
        << "; v3 = " << s.get_vertex(3) << "]";
    return out;
}

void Square::print() {
    std::cout << *this << std::endl;
}
