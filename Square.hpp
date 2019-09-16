#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x, Color c);
    Square(const Square & other);

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;
    double getY() const = delete;
};
