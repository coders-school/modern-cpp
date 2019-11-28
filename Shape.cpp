#include "Shape.hpp"
#include <iostream>

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl
              << "Color " << static_cast<int>(c_) << std::endl;
}
