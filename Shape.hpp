#pragma once

enum class Color : unsigned char {
    red,
    green, 
    blue
};

class Shape
{
    Color c_ = Color::red;
public:
    virtual ~Shape() {}
    Shape(Color c) : c_{c} {}
    Shape() = default;


    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
