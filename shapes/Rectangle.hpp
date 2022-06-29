#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    using Shape::Shape;
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle& operator=(const Rectangle &other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    double x_ = 1.0;
    double y_ = 1.0;
};
