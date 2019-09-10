#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double x, double y)  
    : x_(x),
      y_(y)
{}

Rectangle::Rectangle(Rectangle && other)   noexcept
    : x_(other.getX()),y_(other.getY())
{}

Rectangle &Rectangle::operator= (Rectangle&& object)  noexcept
{
    x_=object.x_;
    y_=object.y_;
    return *this;
}

double Rectangle::getArea() const noexcept
{
    return x_ * y_;
}

double Rectangle::getPerimeter() const
{
    return 2 * (x_ + y_);
}

double Rectangle::getX() const 
{
    return x_;
}

double Rectangle::getY() const
{
    return y_;
}

void Rectangle::print() const
{
    std::cout << "Rectangle:   x: " << getX() << std::endl
              << "             y: " << getY() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
