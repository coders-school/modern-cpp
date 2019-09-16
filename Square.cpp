#include "Square.hpp"
#include <iostream>

Square::Square(double x, Color c)
    : Rectangle(x, x, c)
{}

Square::Square(const Square &other) = default;

double Square::getArea() const
{
    return getX() * getX();
}

double Square::getPerimeter() const
{
    return 4 * getX();
}

void Square::print() const
{
    std::cout << "Square:      x: " << getX() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "         Color: " << static_cast<int>(getColor()) << std::endl << std::endl;
}
