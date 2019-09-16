#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle() = delete;
    Rectangle(const Rectangle&) = default;
    Rectangle(Rectangle&&) noexcept = default;
    Rectangle(double x, double y, Color c);

    Rectangle& operator= (const Rectangle&) = default;
    Rectangle& operator= (Rectangle&&) noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    virtual double getX() const final;
    double getY() const;
    void print() const override;

private:
    double x_;
    double y_;
};
