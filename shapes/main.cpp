#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <type_traits>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [x{10}](shared_ptr<Shape> s)
{
    if(s)
        return (s->getArea() < x);
    return false;
};

void printCollection(const Collection& collection)
{
    for (const auto & it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for (const auto & it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibo(int n) {
    if (n<=2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

template <typename ShapeSubClass,
          std::enable_if_t<std::is_base_of_v<Shape, ShapeSubClass>, int> = 0>
void insertOnlyShapeSubclasses(Collection& collection, const ShapeSubClass& subclass) {
    collection.emplace_back(std::make_shared<ShapeSubClass>(subclass));
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

    constexpr int n = fibo(45);
    Collection shapes {
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

    return 0;
}
