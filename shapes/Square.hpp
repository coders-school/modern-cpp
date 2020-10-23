#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    explicit Square(Color c);
    Square(double x, Color color = Color::Green);
    Square(const Square& other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

private:
    auto getY() = delete;  // should not have Y dimension
    Square() = delete;
};
