#pragma once

enum class Color : unsigned char{
    Red,
    Green,
    Black
};

class Shape
{
public:
    virtual ~Shape() {}
    Shape(Color c);
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
private:
    Color color_ = Color::Green;
};
