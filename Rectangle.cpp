#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double x, double y)
    : Square(x, Color::RED), 
      y_(y)
      
{}

double Rectangle::getArea() const noexcept
{
    return this->getX() * y_;
}

double Rectangle::getPerimeter() const noexcept
{
    return 2 * (this->getX() + y_);
}

double Rectangle::getY() const
{
    return y_;
}

void Rectangle::print() const noexcept
{
    std::cout << "Rectangle:   x: " << getX() << std::endl
              << "             y: " << getY() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
