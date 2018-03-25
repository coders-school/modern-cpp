#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Circle(r, Color::BLUE)
{}

Circle::Circle(double r, Color c)
    : Shape(c), r_(r)
{}

double Circle::getArea() const noexcept
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
