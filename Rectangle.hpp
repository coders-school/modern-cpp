#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;

    double getArea() const;
    double getPerimeter() const;
    double getX() const;
    double getY() const;
    void print() const;

private:
    double x_;
    double y_;
};
