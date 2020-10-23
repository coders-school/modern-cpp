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

constexpr int fibonacci(int sequenceNumber) {
    if (sequenceNumber < 0) {
        return 0;
    }
    return (sequenceNumber < 2) ? sequenceNumber : (fibonacci(sequenceNumber - 1) + fibonacci(sequenceNumber - 2));
}

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr) {
        return false;
    }

    return (first->getArea() < second->getArea());
};

//################# TASK 11 #################

template <typename T, typename = typename std::enable_if<std::is_base_of<Shape, T>::value>>
void insertShapesOnly(Collection& collection, std::shared_ptr<T> shape) {
    collection.emplace_back(shape);
}

//################# TASK 16 #################

auto perimeterBiggerThan20 = [](shared_ptr<Shape> shape) {
    return (shape) ? (shape->getPerimeter() > 20) : (false);
};

auto areaLessThanX = [x{10}](shared_ptr<Shape> shape) {
    return (shape) ? (shape->getArea() < x) : (false);
};

//################# TASK 18 #################

template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
    return std::make_shared<DerivedType>(std::forward<decltype(args)>(args)...);
}

//###########################################

void printCollectionElements(const Collection& collection) {
    for (const auto& el : collection)
        if (el)
            el->print();
}

void printAreas(const Collection& collection) {
    for (const auto& el : collection)
        if (el)
            cout << el->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape> shape)> predicate,
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main() {
    constexpr int fiboResult = fibonacci(45);

    Collection shapes{make_shared<Circle>(2.0),
                      make_shared<Circle>(3.0),
                      nullptr,
                      make_shared<Circle>(4.0),
                      make_shared<Rectangle>(10.0, 5.0),
                      make_shared<Square>(3.0),
                      make_shared<Circle>(4.0)};

    printCollectionElements(shapes);

    Circle c1{Color::Black};
    Rectangle r1{Color::Green};
    Square s1{Color::Red};

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    //################# TASK 11 #################

    auto shapeType = std::make_shared<Rectangle>(5, 2);  //Ok - compilator allow that type
    insertShapesOnly(shapes, shapeType);

    //auto otherType = std::make_shared<int>(2);
    //insertShapesOnly(shapes, otherType);
    //Wrong - compilator doesnt allow other types than types derived from base class - Shape

    //################# TASK 14 #################

    std::cout << "Aligment of Circle: " << alignof(Circle) << '\n';

    //################# TASK 15 #################
    //Inside Rectangle and Square classes

    //################# TASK 16 #################

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    //################# TASK 17 #################

    map<shared_ptr<Shape>, double> mapOfShapes{};
    transform(shapes.cbegin(), shapes.cend(), inserter(mapOfShapes, mapOfShapes.begin()),
              [](const shared_ptr<Shape>& shape) {
                  return (shape) ? pair(shape, shape->getPerimeter()) : pair(shape, 0.0);
              });

    for (const auto& [shape, perimeter] : mapOfShapes) {
        (shape) ? (cout << shape->getPerimeter() << '\n') : (cout << "nullptr! " << perimeter << '\n');
    }

    //################# TASK 18 #################

    auto rectangle = make_shape<Rectangle>(3, 5);
    rectangle->print();

    return 0;
}
