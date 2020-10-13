#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x, Color c = Color::Black);
    Square(const Square & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

private:
    double getY() = delete; // should not have Y dimension
    Square();
};
