#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(const Square&) = default;
    Square(Square&&) noexcept = default;
    Square(double x, Color c);

    Square& operator= (const Square&) = default;
    Square& operator= (Square&&) noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;
    double getY() const = delete;
};
