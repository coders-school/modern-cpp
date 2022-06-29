#pragma once

enum class Color : unsigned char {
    Red,
    Green,
    Yellow,
};

class Shape
{
    Color color = Color::Red;

public:
    Shape() = default;
    Shape(const Shape& other) : color(other.color) {}
    Shape(Color c) : color(c) {}
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
