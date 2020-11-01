#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](auto first, auto second) {
    if (first == nullptr || second == nullptr) {
        return false;
    }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20(shared_ptr<Shape> shape) {
    if (shape) {
        return (shape->getPerimeter() > 20);
    }
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> shape) {
    if (shape) {
        std::cout << "\n*** " << x << " ***\n";
        return shape->getArea() < x;
    }
    return false;
};

void printCollection(const Collection& collection) {
    for (const auto& it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection) {
    for (const auto& it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(std::shared_ptr<Shape>)> predicate,
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibo(int n) {
    if (n <= 2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

template <typename T, typename = typename std::enable_if_t<std::is_base_of<Shape, T>::value>>
void AddShapeToCollection(Collection& collection, std::shared_ptr<T> shape) {
    collection.emplace_back(shape);
}

void FillShapesCollection(Collection& shapes) {
    AddShapeToCollection(shapes, make_shared<Circle>(2.0));
    AddShapeToCollection(shapes, make_shared<Circle>(3.0));
    //AddShapeToCollection(shapes, nullptr); compile error
    shapes.emplace_back(nullptr);
    AddShapeToCollection(shapes, make_shared<Circle>(4.0));
    AddShapeToCollection(shapes, make_shared<Rectangle>(10.0, 5.0));
    AddShapeToCollection(shapes, make_shared<Square>(3.0));
    AddShapeToCollection(shapes, make_shared<Square>(4.0));
}

int main() {
    Collection shapes{};
    FillShapesCollection(shapes);
    printCollection(shapes);
    std::cout << "Alignment of Circle " << alignof(Circle) << '\n';

    Circle c1{3.0, Color::Green};
    Rectangle r1{Color::Black};
    auto values = {1, 2, 3, 4, 5};

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than X");

    return 0;
}
