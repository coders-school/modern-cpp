#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other);
    Rectangle(Rectangle&& other);
    Rectangle& operator=(Rectangle&& other);

    double getArea() const override;
    double getPerimeter() const override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_;
    double y_;
};
