#include <iostream>
import Shape;
export module Rectangle;

export class Rectangle : public Shape
{
public:
    using Shape::Shape;
    Rectangle(double x, double y)    : x_(x),
      y_(y)
{}
    Rectangle(const Rectangle & other) = default;

    double getArea() const noexcept override
    {
    return x_ * y_;
}
    double getPerimeter() const noexcept override{
    return 2 * (x_ + y_);
}
    virtual double getX() const final{
    return x_;
}
    double getY() const{
    return y_;
}
    void print() const override{
    std::cout << "Rectangle:   x: " << getX() << std::endl
              << "             y: " << getY() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}

private:
    Rectangle() = delete;

    double x_{};
    double y_{};
};
