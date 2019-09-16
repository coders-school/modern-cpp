#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x, Color c);
    Square(const Square & other);

    double getArea();
    double getPerimeter();
    void print();
    double getY() const = delete;
};
