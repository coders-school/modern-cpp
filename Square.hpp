#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other);

    double getArea();
    double getPerimeter();
    void print();

private:
    Square();
};
