#include "Circle.hpp"
#include <math.h>
#include <iostream>

static_assert(M_PI != 3.14, "M_PI is not equal to 3.14");

Circle::Circle(double r, Color c)
    : r_(r)
{
    color_ = c;
}

Circle::Circle(const Circle & other)
{
    r_ = other.getRadius();
}

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
              << "     perimeter: " << getPerimeter() << std::endl
              << "         Color: " << static_cast<int>(getColor()) << std::endl << std::endl;
}
