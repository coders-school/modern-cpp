#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other);

    double getArea() const noexcept;
    double getPerimeter() const noexcept;
    double getX() const;
    double getY() const;
    void print() const;

private:
    Rectangle();

    double x_;
    double y_;
};
