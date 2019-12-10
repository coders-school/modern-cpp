#pragma once

#include <string>
#include "Color.hpp"
#include "Shape.hpp"

class alignas(128) Circle : public Shape
{
public:
    Circle(double r) : Circle(r, Color::Blue) {};
    Circle(double r, Color col);
    Circle(const Circle & other);

    double getArea() const noexcept;
    double getPerimeter() const noexcept;
    double getRadius() const;
    double getPi() const;
    void print() const;
    std::string getColorName() const;

private:
    Circle(); // doesn't allow to call default constructor

    double r_;
    Color color;
};
