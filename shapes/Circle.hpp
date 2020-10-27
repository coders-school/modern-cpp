#pragma once

#include "Shape.hpp"

class alignas(128) Circle final : public Shape {
public:
    using Shape::Shape;
    Circle(double r);
    Circle(double r, Color color);
    Circle(const Circle& other) = default;

    [[deprecated("PI is deprecated")]] double getPI() const;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    Circle() = delete;  // doesn't allow to call default constructor

    double r_{};
};
