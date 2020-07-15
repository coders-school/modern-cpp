#pragma once

enum class Colour : unsigned char {
    Red,
    Green,
    Blue
};

class Shape
{
    Colour colour = Colour::Green;
public:
    Shape(Colour c);
    Shape() = default;
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
