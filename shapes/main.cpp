#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea()); };

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) {if(s){
        return (s->getPerimeter() > 20); } return false; };

auto areaLessThanX = [x = 10](shared_ptr<Shape> s) {
    if (s) {
        return (s->getArea() < x);
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
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info) {
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

template <typename T, typename = typename std::enable_if_t<std::is_base_of<Shape, T>::value>>
void insertToCollection(Collection& collection, std::shared_ptr<T>& shape) {
    collection.push_back(shape);
}

template <typename DerivedType, typename... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
    return std::make_shared<DerivedType>(std::forward<decltype(args)>(args)...);
}

int main() {
    Collection shapes{
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
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

    //Exercise 14
    std::cout << "Alignment of Circle " << alignof(Circle) << '\n';
    auto squareToAdd = make_shared<Square>(6.0);
    insertToCollection(shapes, squareToAdd);
    printCollection(shapes);

    //This not working:
    //auto testPointer = std::make_shared<int>(15);
    //insertToCollection(shapes, testPointer);

    //Exercise 17:
    std::map<std::shared_ptr<Shape>, double> shapePerimeter;
    std::shared_ptr<Shape> circl1 = make_shared<Circle>(3.0);
    std::shared_ptr<Shape> rectangle1 = make_shared<Rectangle>(3.0, 4.0);
    std::shared_ptr<Shape> square1 = make_shared<Square>(5.0);

    shapePerimeter.insert({circl1, circl1->getPerimeter()});
    shapePerimeter.insert({rectangle1, rectangle1->getPerimeter()});
    shapePerimeter.insert({square1, square1->getPerimeter()});

    std::cout << "\n\n";
    for (const auto& [key, val] : shapePerimeter) {
        if (key) {
            key->print();
        }
        std::cout << "Perimeter value == " << val << '\n';
    }

    auto testShape = make_shape<Circle>(5);
    testShape->print();
    return 0;
}
