#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other) = default;
    Square(Square &&) = default;
    Square& operator=(Square&&) = default;
    Square& operator=(const Square&) = default;
    using Rectangle::Rectangle;

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

private:
    double getY() = delete; // should not have Y dimension
    Square() = delete;
};
