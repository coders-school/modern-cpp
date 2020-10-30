#include <iostream>
import Shape;   // for Color
import Rectangle;
export module Square;

export class Square : public Rectangle {
public:
    Square(Color c)
        : Rectangle(c) {}
    Square(double x)
        : Rectangle(x, x) {}
    Square(const Square& other) = default;

    double getArea() const noexcept override {
        return getX() * getX();
    }
    double getPerimeter() const noexcept override {
        return 4 * getX();
    }
    void print() const override {
        std::cout << "Square:      x: " << getX() << std::endl
                  << "          area: " << getArea() << std::endl
                  << "     perimeter: " << getPerimeter() << std::endl;
    }

private:
    double getY() = delete;  // should not have Y dimension
    Square() = delete;
};
