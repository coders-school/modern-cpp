#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x);
    Square(const Square & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const override;
    void print() const override;

    double getY() = delete; // should not have Y dimension
};
