#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <memory>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

typedef vector<shared_ptr<Shape>> Collection;

bool areaLessThan10(shared_ptr<Shape> s)
{
    if(s)
        return (s->getArea() < 10);
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            (*it)->print();
}

void printAreas(const Collection& collection)
{
    for(vector<shared_ptr<Shape>>::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            cout << (*it)->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
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

constexpr int fibonacci(int n) {
    if (n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

std::tuple<shared_ptr<Shape>, shared_ptr<Shape>, shared_ptr<Shape>> getVectorElements(const Collection & c) {
    return std::make_tuple(c[0], c[1], c[2]);
}

int main()
{
    // int result = fibonacci(45);
    // std::cout << result;

    std::vector v = {1, 2, 3, 4, 5'000'000};
    // static_assert(false, "Bo tak");

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

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    // auto circle = make_shared<Circle>(4.0);
    // auto pi = circle->getPi();

    findFirstShapeMatchingPredicate(shapes, [](auto s)
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    }, "perimeter bigger than 20");


    auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getArea() < x);
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    alignas(1024) Circle c1{1.0};
    alignas(1024) Circle c2{2.0};

    std::cout << &c1 << '\n' << &c2 << '\n';

    std::map<std::shared_ptr<Shape>, double> mapa;
    std::transform(shapes.begin(), shapes.end(), std::inserter(mapa, mapa.begin()), [](const auto & shape){
        double perimeter = 0;
        if (shape) {
            perimeter = shape->getPerimeter();
        }
        return std::make_pair(shape, perimeter);
    });

    for (const auto & [key, value] : mapa) {
        if (key) {
            key->print();
            std::cout << value << '\n';
        }
    }

    // const auto & [v1, v2, v3] = getVectorElements(shapes);
    // std::cout << v1 << v2 << v3;

    return 0;
}
