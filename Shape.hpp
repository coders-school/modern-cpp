#pragma once

enum class Color : unsigned char
{
    RED,
    BLUE,
    GREEN
};

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const noexcept = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

protected:
    Color color = Color::RED;
};
