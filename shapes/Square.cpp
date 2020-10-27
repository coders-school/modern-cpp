#include "Square.hpp"
#include <iostream>

Square::Square(double x, Color color)
    : Rectangle(x, x, color) {}


double Square::getArea() const noexcept
{
    return getX() * getX();
}

double Square::getPerimeter() const noexcept
{
    return 4 * getX();
}

void Square::print() const
{
    std::cout << "Square:      x: " << getX() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
