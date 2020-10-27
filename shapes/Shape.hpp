#pragma once

enum class Color : unsigned char {
    Red = 'r',
    Green = 'g',
    Blue = 'b'
};

class Shape
{
public:
    explicit Shape(Color color)
        : color_(color) {}
    Shape() = default;
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Color getColor() const { return color_; }

private:
    Color color_ = Color::Red;
};
