#include "Shape.hpp"
#include <iostream>

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

std::string Shape::getName() const
{
    return "Shape";
}

