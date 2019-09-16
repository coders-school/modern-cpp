#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle() = delete;
    Rectangle(double x, double y, Color c);
    Rectangle(const Rectangle & other);

    double getArea() const override;
    double getPerimeter() const override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    double x_;
    double y_;
};
