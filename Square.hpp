#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other) = default;
    Square(Square&& other);
    Square& operator=(Square&& other);

    double getArea();
    double getPerimeter();
    double getY() const = delete;
    void print();

private:
    Square() = delete;
    double x_;
};
