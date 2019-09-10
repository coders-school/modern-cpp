#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle(Rectangle && other) noexcept;  //move constructor

    Rectangle& operator= (Rectangle&& object) noexcept; //move assignment operators

    double getArea() const noexcept override;
    double getPerimeter() const override;
    double getX() const;
    double getY() const;
    void print() const override;

private:
    Rectangle();

    double x_;
    double y_;
};
