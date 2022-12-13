#include "Shape.hpp"
#include <iostream>

Shape::Shape(Color c)
    : color(c)
{}

Shape::Shape()
{}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

std::string Shape::getColor() const
{
    switch (color) {
    case Color::Red:
        return "Red";
    case Color::Blue:
        return "Blue";
    case Color::Green:
        return "Green";
    }
    return "Unknown";
}