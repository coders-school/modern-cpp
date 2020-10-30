#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    using Shape::Shape;
    explicit Rectangle(Color c);
    Rectangle(double x, double y);
    Rectangle(double x, double y, Color c);
    Rectangle(const Rectangle& other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_{};
    double y_{};
};
