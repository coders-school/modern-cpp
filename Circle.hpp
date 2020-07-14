#pragma once

#include "Shape.hpp"

class alignas(128) Circle : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other);

    [[deprecated("Please use M_PI instead")]]
    double getPi() const;

    double getArea() const;
    double getPerimeter() const;
    double getRadius() const;
    void print() const;

private:
    Circle(); // doesn't allow to call default constructor

    double r_;
};
