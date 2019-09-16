#pragma once

#include "Shape.hpp"

// alignas(2) -> can't be set to less than default alignment
class alignas(8) Circle final : public Shape
{
public:
    Circle() = delete;
    Circle(const Circle&) = default;
    Circle(Circle&&) noexcept = default;
    Circle(double r, Color c);

    Circle& operator= (const Circle&) = default;
    Circle& operator= (Circle&&) noexcept = default;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    [[deprecated]]
    double getPi() const;
    void print() const override;

private:
    double r_;
};
