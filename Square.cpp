#include "Square.hpp"
#include <iostream>

Square::Square(double x,  const Color & color)
    : Shape(color), 
      x_(x)
{}

double Square::getArea() const noexcept
{
    return x_ * x_;
}

double Square::getPerimeter() const noexcept
{
    return 4 * x_;
}

double Square::getX() const
{
    return x_;
}

void Square::print() const noexcept
{
    std::cout << "Square:      x: " << x_ << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
