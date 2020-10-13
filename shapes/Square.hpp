#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other) = default;

    double getArea();
    double getPerimeter();
    void print();

private:
    double getY() = delete; // should not have Y dimension
    Square();
};
