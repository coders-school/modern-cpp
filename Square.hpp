#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other);

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

private:
    double getY(); // should not have Y dimension
    Square();
};
