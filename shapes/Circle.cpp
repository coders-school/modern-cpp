#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Circle(r, Color::Black) {}

Circle::Circle(double r, Color color)
    : r_(r), Shape(color) {}

auto Circle::getRadius() const {
    return r_;
}

static_assert(M_PI != 3.14, "PI must be more accurate than 3.14!");

double Circle::getArea() const {
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const {
    return 2 * M_PI * r_;
}

void Circle::print() const {
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

double Circle::getPi() const {
    return 3.14;
}