#pragma once

#include <string>

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getName() const;
    virtual void print() const;
};
