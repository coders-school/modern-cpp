#include <cmath>
#include <iostream>
export module Circle;
import Shape;

export class Circle final : public Shape {
public:
    using Shape::Shape;
    Circle(double r)
        : r_(r) {}

    Circle(const Circle& other) = default;

    [[deprecated("Please use M_PI instead.")]] double getPi() const {
        return 5.0;
    }
    double getArea() const override {
        return M_PI * r_ * r_;
    }
    double getPerimeter() const override {
        return 2 * M_PI * r_;
    }
    auto getRadius() const {
        return r_;
    }
    void print() const override {
        std::cout << "Circle: radius: " << getRadius() << std::endl
                  << "          area: " << getArea() << std::endl
                  << "     perimeter: " << getPerimeter() << std::endl;
    }

private:
    Circle() = delete;  // doesn't allow to call default constructor

    double r_{};
};

static_assert(M_PI != 3.14, "M_PI is only an estimated value");
