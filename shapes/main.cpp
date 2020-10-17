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
    if (first == nullptr || second == nullptr) {
        return false;
    }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) {
    if (s) {
        return (s->getPerimeter() > 20);
    }
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s) {
    if (s) {
        return (s->getArea() < 10);
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

template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
    return std::make_shared<DerivedType>(std::forward<decltype(args)>(args)...);
}

template <typename T, typename = typename std::enable_if_t<std::is_base_of_v<Shape, T>>>
void insertToShapesCollection(Collection& collection, std::shared_ptr<T>& shape) {
    collection.emplace_back(shape);
}

int main() {
    Collection shapes{
        make_shape<Circle>(2.0), make_shape<Circle>(3.0),          nullptr,
        make_shape<Circle>(4.0), make_shape<Rectangle>(10.0, 5.0), make_shape<Square>(3.0),
        make_shape<Circle>(4.0),
    };
    printCollection(shapes);

    Circle c1{Color::Green};
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
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    std::cout << "\n\n***** HOMEWORK PART *****\n";

    std::cout << "Circle alignment is equal to: " << alignof(Circle) << '\n';
    std::cout << "When alignment was set to alignas(2), Circle object was aligned by 8. VSC showed a warning that "
                 "\"alignment cannot be set to less than the default alignment\"\n";

    std::map<std::shared_ptr<Shape>, double> shapeAndPerimeter;
    std::shared_ptr<Shape> rectangleShape = make_shared<Rectangle>(1.0, 2.0);
    std::shared_ptr<Shape> squareShape = make_shared<Square>(3.0);
    std::shared_ptr<Shape> circleShape = make_shared<Circle>(4.0);

    shapeAndPerimeter.insert({rectangleShape, rectangleShape->getPerimeter()});
    shapeAndPerimeter.insert({squareShape, squareShape->getPerimeter()});
    shapeAndPerimeter.insert({circleShape, circleShape->getPerimeter()});

    for (const auto& [key, value] : shapeAndPerimeter) {
        if (key) {
            key->print();
        }
        std::cout << "Perimeter is equal to " << value << "\n\n";
    }

    auto newSquare = make_shape<Square>(1234);
    newSquare->print();

    std::cout << "\n\n SFINAE check\n";
    insertToShapesCollection(shapes, newSquare);
    printCollection(shapes);

    // std::cout << "\n\n SFINAE not allowed and not working check\n";
    // auto notAShape = std::make_shared<double>(15.0);
    // insertToShapesCollection(shapes, notAShape);

    return 0;
}
