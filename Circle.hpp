#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle() = delete; // doesn't allow to call default constructor
    Circle(double r);
    Circle(double r, Color c);
    Circle(const Circle & other) = default;

    double getArea() const noexcept override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    double r_;
};
