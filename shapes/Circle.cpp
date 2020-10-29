#include "Circle.hpp"
#include <math.h>
#include <iostream>

#define M_PI 3.14159265358979323846

// Task 15 - Delegating constructor
Circle::Circle(double r) : Circle(r, Color::Red){};

Circle::Circle(double r, Color c) : r_(r), Shape(c) {}

auto Circle::getRadius() const {
    return r_;
}

double Circle::getPi() const {
    return 5.0;
}

static_assert(M_PI != 3.14, "M_PI is only an estimated value");

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