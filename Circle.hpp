#pragma once

#include "Shape.hpp"

class Circle : public Shape
{
public:
    Circle() = delete;
    Circle(double r, Color c);
    Circle(const Circle & other);

    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    void print() const;

private:
    double r_;
};
