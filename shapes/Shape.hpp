#pragma once

enum class Color : unsigned char {
    Red,
    Green,
    Black
};

class Shape {
    Color color_;

public:
    explicit Shape(Color);
    Shape() = default;
    virtual ~Shape() {}

    virtual auto getArea() const -> double = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual void getColor();
};
