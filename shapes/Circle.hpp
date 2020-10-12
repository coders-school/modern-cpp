#pragma once

#include "Shape.hpp"

class alignas(128) Circle final : public Shape
// class alignas(2) Circle final : public Shape  cannot set to less than default
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    
    [[deprecated("Please use M_PI instead.")]]
    double getPi() const;
    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_{};
};
