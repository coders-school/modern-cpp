#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection& collection)
{
    for(auto it = collection.cbegin(); it != collection.cend(); ++it)
    {
        if(*it != nullptr)
        {
            (*it)->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(const auto & it : collection)
    {
        if(it != nullptr)
        {
            cout << it->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.cbegin(), collection.cend(), predicate);
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

constexpr int fibonacci(const int n)
{
    if (n <= 2)
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    constexpr int x = fibonacci(45);
    cout << x;
    Collection shapes = {
        make_shared<Circle>(2.0, Color::GREEN),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
        {
            return false;
        }
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, [](auto s)
    {
        if(s)
        {
            return (s->getPerimeter() > 20);
        }
        return false;
    }, "perimeter bigger than 20");

    auto areaLessThanX = [x = 10](auto s)
    {
        if(s)
        {
            return (s->getArea() < x);
        }
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    return 0;
}

