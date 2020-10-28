#pragma once

#include "Shape.hpp"

class alignas(128) Circle final : public Shape
{
public:
    Circle(double r, Color c);
    Circle(double r);
    Circle(const Circle & other) = default;

    [[deprecated("Please use M_PI instead getPi() method")]]
    double getPi() const;
    double getArea() const override;
    double getPerimeter() const override;
    auto getRadius() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
