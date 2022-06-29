#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    using Rectangle::Rectangle;
    Square() = delete;
    Square(double x);
    Square(const Square & other) = default;
    Square& operator=(const Square &other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

    double getY() = delete; // should not have Y dimension

    // double (*ptr)() noexcept = getArea;
};
