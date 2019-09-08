#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other);
    Square(Square&& other);
    Square& operator=(Square&& other);

    double getArea();
    double getPerimeter();
    void print();

private:
    Square();
};
