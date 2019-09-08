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

Circle::Circle(Circle&& other) : r_(0.0)
{
    r_ = other.r_;
    other.r_ = 0.0;
}

Circle& Circle::operator=(Circle&& other)
{
    if (this != &other)
    {
        r_ = other.r_;
        other.r_ = 0.0;
    }
    return *this;
}

double Circle::getArea() const
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const noexcept
{
    return r_;
}

double Circle::getPi() const noexcept
{
    return M_PI;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
