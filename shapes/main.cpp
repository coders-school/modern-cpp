#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <string>
#include <type_traits>
#include <utility>
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
auto areaLessThanX = [x{10}](shared_ptr<Shape> s) {
    if (s) {
        return (s->getArea() < x);
    }
    return false;
};

void printCollectionElements(const Collection& collection) {
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
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

template <typename T, typename = typename std::enable_if<std::is_base_of<Shape, T>::value>>
void collectionInsert(Collection& collection, std::shared_ptr<T>& shape) {
    collection.emplace_back(shape);
}

int main() {
    Collection shapes;
    shapes.push_back(make_shared<Circle>(2.0));
    shapes.push_back(make_shared<Circle>(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(make_shared<Circle>(4.0));
    shapes.push_back(make_shared<Rectangle>(10.0, 5.0));
    shapes.push_back(make_shared<Square>(3.0));
    shapes.push_back(make_shared<Circle>(4.0));
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

    //Exercise 11 CHECK
    auto circleAdd = std::make_shared<Circle>(5);
    collectionInsert(shapes, circleAdd);
    printCollectionElements(shapes);
    //Exercise 11 NOT WORKING EXAMPLE
    //auto test = std::make_shared<int>(10);
    //collectionInsert(shapes, test);

    //EXERCISE 14 CHECK
    std::cout << "Circle Align " << alignof(Circle) << '\n';

    //EXERCISE 17 CHECK
    std::map<std::shared_ptr<Shape>, double> shapePerimeters;
    transform(shapes.begin(), shapes.end(), inserter(shapePerimeters, shapePerimeters.begin()),
              [](const shared_ptr<Shape>& s) {
                  return s ? pair{s, s->getPerimeter()} : pair{s, 0.0};
              });
    for (const auto& [key, val] : shapePerimeters) {
        if (key) {
            key->print();
        }
        std::cout << "Perimeter value == " << val << '\n';
    }
    return 0;
}
