#include "Circle.hpp"
#include <math.h>
#include <iostream>

static_assert(M_PI != 3.14, "M_PI is only an estimated value");

Circle::Circle(double r, Color color)
    : Shape(color), r_(r) {}

double Circle::getPI() const {
    return M_PI;
}

double Circle::getArea() const {
    return getPI() * r_ * r_;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * r_;
}

double Circle::getRadius() const {
    return r_;
}

void Circle::print() const {
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
