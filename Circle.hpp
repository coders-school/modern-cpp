#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle(Circle &&) noexcept = default;
    Circle& operator=(Circle &&) noexcept = default;
    Circle& operator=(const Circle &) = default;
    using Shape::Shape;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_{};
};
