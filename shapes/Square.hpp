#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    Square(Color c);
    Square(double x);
    Square(double x, Color c);
    Square(const Square& other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

private:
    double getY() = delete;  // should not have Y dimension
    Square() = delete;
};
