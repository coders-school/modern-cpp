#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color c = Color::Red)
    : color_(c)
{
}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

void Shape::getColor() {
    if(color_ == Color::Red) {
    std::cout << "It's red\n";
    }
    if(color_ == Color::Green) {
    std::cout << "It's green\n";
    }
    if(color_ == Color::Black) {
    std::cout << "It's black\n";
    }
}
