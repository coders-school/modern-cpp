#pragma once

enum class Color
{
    R = 11,
    G,
    B
};

class Shape
{
public:
    Shape() = default;
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    Color getColor() const;

protected:
    Color color_;
};
