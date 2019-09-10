#pragma once

enum class Color
{
    RED,
    GREEN,
    BLUE
};

class Shape
{
  //  Color color;
public:
   // Shape(Color);
   Color color;
    virtual ~Shape() {}

    virtual double getArea() const noexcept = 0 ;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
   
};
