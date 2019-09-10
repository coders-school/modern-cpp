#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : r_(r)
{}

Circle::Circle(Circle && other)  noexcept: r_(other.getRadius()), data(std::move(other.data))
{
   std::cout<<"this->data = "<<this->data<<std::endl;
   std::cout<<"other.data = "<<other.data<<std::endl;
   std::cout<<"Circle::Circle(Circle && other)"<<r_<<std::endl;
}

Circle &Circle::operator= (Circle&& object) noexcept
{
    r_=object.r_;
    return *this;
}


double Circle::getArea() const noexcept
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

[[deprecated]]double Circle::getPi()  //zad 9
{
    return M_PI;
}

struct PIValueCheckn  // zad 1
{
    static_assert(M_PI != 3.14, "M_PI defined in math library is not equal to 3.14");
};
