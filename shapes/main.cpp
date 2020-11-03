#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

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
    if (s)
        return (s->getArea() < x);
    return false;
};

void printCollection(const Collection& collection)
{
    for (const auto& it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for (const auto& it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibo(int n)
{
    if (n <= 2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

template <typename ShapeSubClass, std::enable_if_t<std::is_base_of_v<Shape, ShapeSubClass>, int> = 0>
void insertOnlyShapeSubclasses(Collection& collection, const ShapeSubClass& subclass)
{
    collection.emplace_back(std::make_shared<ShapeSubClass>(subclass));
}

std::map<std::shared_ptr<Shape>, double> shapePerimeter{
    {std::make_shared<Circle>(3.0), std::make_shared<Circle>(3.0)->getPerimeter()},
    {std::make_shared<Rectangle>(3.0, 5.0), std::make_shared<Rectangle>(3.0, 5.0)->getPerimeter()},
    {std::make_shared<Square>(4.0), std::make_shared<Square>(4.0)->getPerimeter()},
};

template <typename ShapeSubclass, typename... Args>
std::shared_ptr<Shape> make_shape(Args&&... args) {
    return std::make_shared<ShapeSubclass>(std::forward<Args>(args)...);
}

int main()
{
    std::string dash(50, '-');
    std::cout << dash << '\n';
    std::cout << "Circle alignment: " << alignof(Circle) << '\n';
    std::cout << dash << '\n';
    std::cout << dash << '\n';
    std::cout << "Rectangle alignment: " << alignof(Rectangle) << '\n';
    std::cout << dash << '\n';

    for (const auto& [shapePtr, perimeter] : shapePerimeter) {
        shapePtr->print();
        std::cout << "Shape perimeter: " << perimeter << '\n';
    }
    std::cout << dash << '\n';

    auto CirclePtr = make_shape<Circle>(3.0);
    auto RedCirclePtr = make_shape<Circle>(3.0, Color::Red);

    Collection shapes{
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };

    insertOnlyShapeSubclasses(shapes, Circle(5.1));
    printCollection(shapes);

    Circle c1{Color::Green};
    Circle c2{5.0, Color::Red};
    Rectangle r1{Color::Black};

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}
