#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    using Shape::Shape;
    Rectangle(double x, double y);
    Rectangle(double x, double y, Color color);
    Rectangle(const Rectangle& other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getX() const;
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_{};
    double y_{};
};
