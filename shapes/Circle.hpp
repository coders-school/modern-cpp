#pragma once

#include "Shape.hpp"

//alignas(2) fails on clang
class alignas(128) Circle final : public Shape {
public:
    using Shape::Shape;
    Circle(double r, Color c = Color::Black);
    Circle(const Circle& other) = default;

    [[deprecated("Please use M_PI instead.")]] double getPi() const;
    double getArea() const override;
    double getPerimeter() const override;
    auto getRadius() const;
    void print() const override;

private:
    Circle() = delete;  // doesn't allow to call default constructor

    double r_{};
};
