#pragma once

#include "Shape.hpp"

// alignas(128) -  new of type circle extend alinment 128. after commanting target options in Cmakeu works.
// alignas(2) alignas can't be set to lessthan default alignament
class alignas(16) Circle final: public Shape
{
public:
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle(const Circle && other) noexcept;

    double getArea() const noexcept override ;
    double getPerimeter() const noexcept override;
    double getRadius() const;

    [[deprecated]]
    double getPI() const;
    void print() const noexcept override;

    Circle& operator=(Circle && other) noexcept = default;

private:
    

    double r_;
};
