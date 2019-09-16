#pragma once

#include "Shape.hpp"

class alignas(2) Circle final : public Shape
{
public:
    Circle() = delete;
    Circle(double r, Color c);
    Circle(const Circle & other);

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    [[deprecated]]
    double getPi() const;
    void print() const override;

private:
    double r_;
};
