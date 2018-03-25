#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x);
    Square(const Square & other) = default;

    double getArea();
    double getPerimeter();
    void print();

    double getY() = delete; // should not have Y dimension
};
