#pragma once

#include "Square.hpp"

class Rectangle : public Square
{
public:
    Rectangle() = delete;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other) = default;
    Rectangle(const Rectangle && other) noexcept;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getY() const;
    void print() const noexcept override;

    Rectangle& operator=(Rectangle && other) noexcept = default;
private:
    

    
    double y_;
};
