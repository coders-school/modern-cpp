#pragma once
#include <string>

enum struct Color : unsigned char {
    Red,
    Green,
    Blue,
};

class Shape
{
    Color color = Color::Red;

public:
    Shape(Color c);
    Shape();
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    std::string getColor() const;
};
