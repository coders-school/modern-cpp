#pragma once
#include <math.h>

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    using Shape::Shape;
    Circle() = delete;
    explicit Circle(double r);
    Circle(const Circle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    double r_ = 0.0;
};
