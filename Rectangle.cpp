#include <cmath>
#include <stdexcept>
#include "Rectangle.h"

static bool almost_equal(double a, double b) {
    return std::fabs(a - b) < 1e-9;
}

bool Rectangle::check(Point2D* vertices) {
    return almost_equal(Point2D::distance(vertices[0], vertices[1]),
                        Point2D::distance(vertices[2], vertices[3])) &&
           almost_equal(Point2D::distance(vertices[1], vertices[2]),
                        Point2D::distance(vertices[3], vertices[0]));
}

Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind > N_VERTICES - 1) {
        throw std::out_of_range("Indice fuera de rango");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    if (ind < 0 || ind > N_VERTICES - 1) {
        throw std::out_of_range("Indice fuera de rango");
    }
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        set_color(r.get_color());
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.get_color()
        << "; v0 = " << r.vs[0]
        << "; v1 = " << r.vs[1]
        << "; v2 = " << r.vs[2]
        << "; v3 = " << r.vs[3] << "]";
    return out;
}

double Rectangle::area() const {
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const {
    return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << *this << std::endl;
}
