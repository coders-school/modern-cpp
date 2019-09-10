#include "Shape.hpp"
#include <iostream>

Shape::Shape(const Color & color) : color_(color)
{}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
