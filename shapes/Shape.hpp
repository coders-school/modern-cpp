#pragma once

enum class Color : unsigned char {
    Red,
    Green,
    Black
};

class Shape {
    Color color_{Color::Red};

public:
    Shape() = default;
    explicit Shape(Color color);
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
