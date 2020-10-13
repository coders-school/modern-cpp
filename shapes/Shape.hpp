#pragma once

enum class Color : unsigned char {
    RED,
    GREEN,
    BLUE
};

class Shape
{
public:
    explicit Shape(Color);
    Shape() = default;
    virtual ~Shape() {}

    virtual auto getArea() const -> double = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

private:
    Color color_ = Color::RED;
};
