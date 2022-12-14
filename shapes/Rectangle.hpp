#pragma once

#include "Shape.hpp"

class alignas(64) Rectangle : public Shape
{
public:
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    using Shape::Shape;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    double x_ = 1.0;
    double y_ = 1.0;
};
