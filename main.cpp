#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <math.h>
#include <memory>

using namespace std;

using Collection = vector<std::shared_ptr<Shape>>;

auto perimeterBiggerThan20 = [&](std::shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [&](std::shared_ptr<Shape> s, int X=10)
{
    if(s)
        return (s->getArea() < X);
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
            it->print();
    }
}

void printAreas(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
            cout << it->getArea() << std::endl;
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     auto& lambda,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), lambda);
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

constexpr int fibo(int number)
{
    if (number == 1 || number == 0)
        return number;
    return (fibo(number-1) + fibo(number -2));
}

template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
   return std::make_shared<DerivedType>(std::forward<Arguments>(args)...);
}

int main()
{
    //static_assert(M_PI == 3.14, "wrong"); //zadanie 1

    int n = fibo(45);
    std::cout<< n;
    alignas(2) Circle a(1);    
    std::cout<< "\n" << sizeof(a) << std::endl;
    static_assert(alignof(a) == 2);

    Collection shapes = {
        std::make_shared<Circle>(2.0),
        std::make_shared<Circle>(3.0),
        std::shared_ptr<Shape>(nullptr),
        std::make_shared<Circle>(4.0),
        std::make_shared<Rectangle>(10.0, 5.0),
        std::make_shared<Square>(3.0),
        std::make_shared<Circle>(4.0),
        make_shape<Circle>(9.9),
        make_shape<Rectangle>(1.1, 2.2)
                        };
   
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), 
        [&](auto& first, auto& second)->bool{
            if (first == nullptr || second == nullptr)
                return false;
            return first->getArea() < second-> getArea();
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    std::shared_ptr<Shape> square(new Square(4.0));
    shapes.push_back(square);

    std::unique_ptr<Shape> a1(new Circle(9.0));
    shapes.push_back(std::move(a1));

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");
    
    return 0;
}

