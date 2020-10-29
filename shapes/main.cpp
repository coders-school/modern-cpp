#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;
// Task 16 - Lambda functions
auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) { return (s) ? (s->getPerimeter() > 20) : (false); };

auto areaLessThanX = [x{10}](shared_ptr<Shape> s) { return (s) ? (s->getArea() < x) : (false); };

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
                                     std::function<bool(shared_ptr<Shape> s)> predicate,
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter) {
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

// Task 11 - Sfinae
template <typename T, typename = typename std::enable_if<std::is_base_of<Shape, T>::value>>
void insertOnlyShapes(Collection& collection, std::shared_ptr<T> shape) {
    collection.emplace_back(shape);
}

// Task 18 - Variadic template
template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
    return make_shared<DerivedType>(decltype(args)(args)...);
}

int main() {
    constexpr int n = fibo(45);
    Collection shapes{
        make_shared<Circle>(2.0), make_shared<Circle>(3.0),          nullptr,
        make_shared<Circle>(4.0), make_shared<Rectangle>(10.0, 5.0), make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };
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
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    // Task 11 - Sfinae
    insertOnlyShapes(shapes, make_shape<Circle>(6.0));
    insertOnlyShapes(shapes, make_shape<Rectangle>(7.0, 9.0));
    printCollection(shapes);

    // Task 14 - Alignas/alignof
    std::cout << "Aligment of Circle: " << alignof(Circle) << '\n';

    // Task 17 - Structured bindings
    std::map<shared_ptr<Shape>, double> shapesMap{};
    transform(shapes.cbegin(), shapes.cend(), inserter(shapesMap, shapesMap.begin()),
              [](const shared_ptr<Shape>& shape) {
                  return (shape) ? std::make_pair(shape, shape->getPerimeter()) : std::make_pair(shape, 0.0);
              });

    for (const auto& [shape, perimeter] : shapesMap) {
        if (shape) {
            shape->print();
        } else {
            std::cout << "nullptr\n";
        }
        std::cout << "Perimeter value - " << perimeter << '\n';
    }

    // Task 18 - Variadic Templates
    auto r2 = make_shape<Rectangle>(4.0, 8.0);
    r2->print();

    return 0;
}