#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;

    double getArea() const;
    double getPerimeter() const;
    auto getRadius() const;
    void print() const;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
