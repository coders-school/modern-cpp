#include <algorithm>
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

bool sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(shared_ptr<Shape> s) {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
}

bool areaLessThan10(shared_ptr<Shape> s) {
    if (s)
        return (s->getArea() < 10);
    return false;
}

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
                                     bool (*predicate)(shared_ptr<Shape> s),
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
    //make_shared<Circle>(2.0),
    //make_shared<Circle>(3.0),
    //nullptr,
    //make_shared<Circle>(4.0),
    //make_shared<Rectangle>(10.0, 5.0),
    //make_shared<Square>(3.0),
    //make_shared<Circle>(4.0),
    FillShapesCollection(shapes);

    printCollection(shapes);

    Circle c1{Color::Green};
    // auto pi = c1.getPi();
    Rectangle r1{Color::Black};
    // Square s1{};
    auto values = {1, 2, 3, 4, 5};
    // std::cout << values[2];

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    return 0;
}
