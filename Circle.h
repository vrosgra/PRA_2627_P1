#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {

private:
    Point2D center;   // Centro del círculo
    double radius;    // Radio del círculo

public:
    // Constructores
    Circle();
    Circle(std::string color, Point2D center, double radius);

    // Consultores y modificadores
    Point2D get_center() const;
    void set_center(Point2D p);
    double get_radius() const;
    void set_radius(double r);

    // Métodos heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;

    // Impresión por pantalla
    friend std::ostream& operator<<(std::ostream &out, const Circle &c);
};

#endif
