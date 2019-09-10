#pragma once

#include "Shape.hpp"
#include <string>

class alignas(128) Circle final : public Shape  //zad 12
{
public:
    Circle(double r);
    Circle(const Circle & other) = default;
    Circle(Circle && other) noexcept;  //move constructor

    Circle& operator= (Circle&& object) noexcept; //move assignment operators

    double getArea() const noexcept override ;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    double getPi();

private:
    Circle(); // doesn't allow to call default constructor
    std::string data ="hello";
    double r_;
};
