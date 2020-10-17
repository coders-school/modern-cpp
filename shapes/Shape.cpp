#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color color) : color_(color) {}

void Shape::print() const {
    std::cout << "Unknown Shape" << std::endl;
}
