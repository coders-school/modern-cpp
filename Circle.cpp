#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r, Color col)
    : r_(r), color(col)
{}

Circle::Circle(const Circle & other)
{
    r_ = other.getRadius();
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


double Circle::getPi() const
{
    return M_PI;
}

std::string Circle::getColorName() const
{
    switch (color) {
    case Color::Red: return "Red";
    case Color::Green: return "Green";
    case Color::Blue: return "Blue";
    }
    return "Undefined color";
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         color: " << getColorName() << std::endl;
}
