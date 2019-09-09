#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(const Circle & other);
    Circle(Circle&& other);
    Circle& operator=(Circle&& other);

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const noexcept;
    [[deprecated]]
    double getPi() const noexcept;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
