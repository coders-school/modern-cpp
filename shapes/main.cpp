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

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
};

std::function<bool(shared_ptr<Shape>)> areaLessThanX{[x{10}](shared_ptr<Shape> s) {
    return s ? s->getArea() < x : false;
}};

template <typename T>
using IsDerivedFromShape = std::enable_if_t<std::is_base_of_v<Shape, std::remove_reference_t<T>>>;

template <typename T,
          typename = IsDerivedFromShape<T>>
void printShape(T&& shape) {
    shape.print();
}

void printCollectionElements(const Collection& collection) {
    for (const auto& it : collection)
        if (it) {
            printShape(*it);
        }
}

void printAreas(const Collection& collection) {
    for (const auto& it : collection)
        if (it) {
            cout << (it)->getArea() << std::endl;
        }
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

constexpr int fibo(int num) {
    return num <= 2 ? 1 : fibo(num - 1) + fibo(num - 2);
}

template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
    return std::make_shared<DerivedType>(std::forward<decltype(args)>(args)...);
}

int main() {
    Collection shapes{make_shape<Circle>(2.0),
                      make_shape<Circle>(3.0),
                      nullptr,
                      make_shape<Circle>(4.0),
                      make_shape<Rectangle>(10.0, 5.0),
                      make_shape<Square>(3.0),
                      make_shape<Circle>(4.0)};

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    map<shared_ptr<Shape>, double> shapesMap;
    transform(shapes.begin(), shapes.end(), inserter(shapesMap, shapesMap.begin()),
              [](const shared_ptr<Shape>& shape) { return shape ? pair{shape, shape->getPerimeter()} : pair{shape, 0.0}; });

    for (const auto& [shape, perimeter] : shapesMap) {
        if (shape) {
            shape->print();
        } else {
            std::cout << "nullptr\n";
        }
        std::cout << "Perimeter: " << perimeter << "\n\n";
    }

    cout << "Alignof circle: " << alignof(Circle) << '\n';
    Circle circle{Color::Red};
    cout << "Alignof circle: " << alignof(circle) << '\n';
    Rectangle rect{Color::Blue};
    Square sq{Color::Green};

    printShape(Circle{4.});
    printShape(rect);

    constexpr int i = fibo(25);
    cout << "Fibo: " << i << '\n';

    return 0;
}
