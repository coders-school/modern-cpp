#include <iostream>
export module Shape;

export enum class Color : unsigned char {
    Red,
    Green,
    Black
};

export class Shape
{
    Color color_ = Color::Red;
public:
    explicit Shape(Color c) : color_(c) {}
    Shape() = default;
    virtual ~Shape() {}

    virtual auto getArea() const -> double = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const {
        std::cout << "Unknown Shape" << std::endl;
    }
};
