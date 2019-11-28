#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle(Rectangle&&) = default;
    Rectangle& operator=(Rectangle&&) = default;
    Rectangle& operator=(const Rectangle&) = default;
    using Shape::Shape;

    double getArea() const override;
    double getPerimeter() const override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_{};
    double y_{};
};
