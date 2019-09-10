#pragma once

enum class Color
{
    RED,
    BLUE,
    YELLOW
};

class Shape
{
private:
    Color color_;

public:
    Shape() = default;
    Shape(const Color & color);
    Shape(const Shape&) = default;
    Shape(Shape&&) = default;

    virtual ~Shape() {}

    virtual double getArea() const = 0 ;
    virtual double getPerimeter() const = 0 ;
    virtual void print() const;
};
