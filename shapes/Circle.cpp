#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : r_(r)
{}

Circle::Circle(const Circle & other)
{
    r_ = other.getRadius();
}

static_assert(M_PI != 3.14, "M_PI is only an estimated value");

double Circle::getArea() const
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
