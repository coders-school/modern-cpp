#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double x, double y)
    : x_(x),
      y_(y)
{}

Rectangle::Rectangle(Rectangle&& other) : x_(0.0), y_(0.0)
{
    x_ = other.x_;
    y_ = other.y_;
    other.x_ = 0.0;
    other.y_ = 0.0;
}

Rectangle& Rectangle::operator=(Rectangle&& other)
{
    if (this != &other)
    {
        x_ = other.x_;
        y_ = other.y_;
        other.x_ = 0.0;
        other.y_ = 0.0;
    }
    return *this;
}


double Rectangle::getArea() const
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
