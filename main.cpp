#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;
using Collection = vector<std::shared_ptr<Shape>>;
using SPtrShape = std::shared_ptr<Shape>;

template<class DerivedType, class ... Arguments>
std::shared_ptr<DerivedType> make_shape(Arguments&& ... args)
{
    return std::make_shared<DerivedType>(std::forward<Arguments>(args)...);
}

auto sortByArea = [](SPtrShape first, SPtrShape second)
{
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](SPtrShape s)
{
    if (s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX(const unsigned x)
{
    // cannot use &x: l-val reference to r-value
    return [x](SPtrShape s)
    {
        if (s)
            return (s->getArea() < x);
        return false;
    };
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

template<class Predicate>
void findFirstShapeMatchingPredicate(const Collection& collection,
                                     Predicate predicate,
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
    auto uniquePtr1 = std::make_unique<Rectangle>(1.0, 2.0, Color::G);
    auto uniquePtr2 = std::make_unique<Square>(3.0, Color::G);
    auto uniquePtr3 = std::make_unique<Circle>(1.0, Color::B);

    Collection shapes {
        std::shared_ptr<Circle>(new Circle(2.0, Color::R)),
        std::shared_ptr<Circle>(new Circle(3.0, Color::G)),
        nullptr,
        std::shared_ptr<Circle>(new Circle(4.0, Color::B)),
        std::shared_ptr<Rectangle>(new Rectangle(10.0, 5.0, Color::B)),
        std::shared_ptr<Square>(new Square(3.0, Color::G)),
        std::shared_ptr<Circle>(new Circle(4.0, Color::B)),
        std::shared_ptr<Rectangle>(std::move(uniquePtr1)),
        std::shared_ptr<Square>(std::move(uniquePtr2)),
        std::shared_ptr<Circle>(std::move(uniquePtr3)),
        make_shape<Rectangle>(0.5, 3.0, Color::B),
        make_shape<Square>(3.0, Color::G),
        make_shape<Circle>(1.0, Color::G)
    };

    if ( !(uniquePtr1 && uniquePtr2 && uniquePtr3 && uniquePtr3) )
        std::cout << "Move succeed!\n";
    
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = std::shared_ptr<Square>(new Square(4.0, Color::B));
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX(10), "area less than 10");

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
