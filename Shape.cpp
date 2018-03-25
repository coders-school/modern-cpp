#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color c)
    : color(c)
{}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
