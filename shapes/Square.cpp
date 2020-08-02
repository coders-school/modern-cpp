#include "Square.hpp"
#include <iostream>

Square::Square(double x)
    : Rectangle(x, x)
{}

Square::Square(const Square &other)
    : Rectangle(other.getX(), other.getX())
{}

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
