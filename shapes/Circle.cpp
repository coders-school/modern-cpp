#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : Circle(r, Color::Green) 
    {}

Circle::Circle(double r, Color color)
    : Shape(color), r_(r) 
    {}

double Circle::getRadius() const
{
    return r_;
}

double Circle::getPi() const 
{
    return M_PI;
}

static_assert(M_PI != 3.14, "M_PI is only an estimated value");

double Circle::getArea() const
{
    return getPi() * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}



void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
