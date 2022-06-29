#pragma once

#include "Shape.hpp"

class alignas(2) Circle final : public Shape
{
public:
    using Shape::Shape;
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle& operator=(const Circle &other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

    [[deprecated("Please use M_PI instead")]]
    double getPi() const;

private:
    double r_ = 1.0;
};
