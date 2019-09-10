#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(const Square & other) = default;
    Square(Square && other) noexcept;  //move constructor

    Square& operator= (Square&& object) noexcept; //move assignment operators

    double getArea()const noexcept override;
    double getPerimeter()const override;
    void print() const override;

private:
    double getY(); // should not have Y dimension
    Square();
};
