#include "Square.hpp"
#include <iostream>

Square::Square(double x)
    : Rectangle(x, x)
{}

Square::Square(Square&& other) noexcept : Rectangle(0.0, 0.0)
{
    x_ = other.x_;
    other.x_ = 0.0;
}

Square& Square::operator=(Square&& other) noexcept
{
    if (this != &other)
    {
        x_ = other.x_;
        other.x_ = 0.0;
    }
    return *this;
}


double Square::getArea()
{
    return getX() * getX();
}

double Square::getPerimeter()
{
    return 4 * getX();
}

void Square::print()
{
    std::cout << "Square:      x: " << getX() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
