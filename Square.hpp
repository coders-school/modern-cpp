#pragma once

#include "Shape.hpp"

class Square : public Shape
{
public:
    Square() = delete;
    Square(double x, const Color & color = Color::YELLOW);
    Square(const Square & other) = default;
    Square(Square && other) noexcept;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getX() const;
    void print()  const noexcept override;

    Square& operator=(Square && other) noexcept = default;
private:
    double x_;
};
