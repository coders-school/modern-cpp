#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle() = delete;
    Circle(double r, Color c);
    Circle(const Circle & other);

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    double r_;
};
