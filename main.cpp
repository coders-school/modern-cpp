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
#include <initializer_list>

using namespace std;

using Collection = vector<std::shared_ptr<Shape>>;

bool sortByArea(std::shared_ptr<Shape> first, std::shared_ptr<Shape> second)
{
    [=](bool){
        if(first == nullptr || second == nullptr)
        {
            return false;
        }
        return (first->getArea() < second->getArea());
    };
}

bool perimeterBiggerThan20(std::shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

bool areaLessThan10(std::shared_ptr<Shape> s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

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
                                     bool (*predicate)(std::shared_ptr<Shape> s),
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

constexpr int fibo(int number)
{
    if (number == 1 || number == 0)
    {
        return number;
    }
    return (fibo(number-1) + fibo(number -2));
}

int main()
{
    //static_assert(M_PI == 3.14, "wrong"); //zadanie 1

    int n = fibo(45);
    std::cout<< n;
    alignas(2) Circle a(1);    
    std::cout<< "\n" << sizeof(a) << std::endl;
    static_assert(alignof(a) == 2);

    Collection shapes = std::initializer_list<std::shared_ptr<Shape>>{new Circle(2.0), new Circle(3.0), nullptr, new Circle(4.0), new Rectangle(10.0, 5.0), new Square(3.0), new Circle(4.0)};
   
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    std::shared_ptr<Shape> square(new Square(4.0));
    shapes.push_back(square);

    std::unique_ptr<Shape> a1(new Circle(9.0));
    shapes.push_back(std::move(a1));

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");
    
    return 0;
}


