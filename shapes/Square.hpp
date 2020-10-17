#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    Square(Color color);
    Square(double x, Color color = Color::Black);
    Square(const Square& other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

private:
    double getY() = delete;  // should not have Y dimension
    Square() = delete;
};
