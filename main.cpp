#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<Shape*>;

bool sortByArea(Shape* first, Shape* second)
{
    if(first == nullptr || second == nullptr)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(Shape* s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

bool areaLessThan10(Shape* s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(const auto & elements : collection)
    {
        if(elements != nullptr)
        {
            elements->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(const auto & elements : collection)
    {
        if(elements != nullptr)
        {
            cout << elements->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(Shape* s),
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

constexpr unsigned calculateFibonacciNumber(unsigned n)
{
    if (n<2)
        return n;
    return (calculateFibonacciNumber(n-2) + calculateFibonacciNumber(n-1));
}

int main()
{
    Collection shapes;
    shapes.push_back(new Circle(2.0, Color::R));
    shapes.push_back(new Circle(3.0, Color::G));
    shapes.push_back(nullptr);
    shapes.push_back(new Circle(4.0, Color::B));
    shapes.push_back(new Rectangle(10.0, 5.0, Color::R));
    shapes.push_back(new Square(3.0, Color::G));
    shapes.push_back(new Circle(4.0, Color::B));

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto* square = new Square(4.0, Color::B);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    // calculateFibonacciNumber(45);
    // piotr@mintVm:~/git/modern_cpp/build$ time ./modern_cpp
    // >> constexpr unsigned calculateFibonacciNumber(unsigned n) <<:
    // real	0m0,001s
    // user	0m0,001s
    // sys	0m0,000s
    // >> unsigned calculateFibonacciNumber(unsigned n) <<:
    // real	0m5,942s
    // user	0m5,924s
    // sys	0m0,000s

    std::cout << "alignof(Circle): " << alignof(Circle) << '\n';
    // >> class alignas(128) Circle final : public Shape <<:
        // alignof(Circle): 128
    // >> class alignas(2) Circle final : public Shape <<:
        // alignof(Circle): 8
    
    return 0;
}
