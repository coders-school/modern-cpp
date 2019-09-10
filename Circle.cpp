#include "Circle.hpp"
#include <math.h>
#include <iostream>

static_assert(M_PI == 3.14159265358979323846, "M_PI is not equal 3.14159265358979323846");

Circle::Circle(double r)
    : Shape(Color::BLUE),
      r_(r)
      
{}

Circle::Circle(const Circle && other) noexcept
{
    r_ = other.r_;
}

double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

double Circle::getPI() const
{
    return M_PI;
}

void Circle::print() const noexcept
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
