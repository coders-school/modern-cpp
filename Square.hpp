#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other);

    double getArea();
    double getPerimeter();
    std::string getName() const;
    void print();

private:
    double getY(); // should not have Y dimension
    Square();
};
