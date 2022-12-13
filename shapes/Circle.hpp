#pragma once

#include <cmath>
#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle() = delete; // doesn't allow to call default constructor
    Circle(double r);
    Circle(const Circle & other) = default;
    using Shape::Shape;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    static_assert(M_PI != 3.14, "M_PI is rounded");
    double r_ = 1.0;
};
