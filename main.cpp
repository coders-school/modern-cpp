#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

#include "memory"

using  Collection = std::vector<std::shared_ptr<Shape>>;

template<class TShape, class ... Args>
std::shared_ptr<TShape> make_shape(Args&& ... args) {
    return std::make_shared<TShape>(std::forward<Args>(args)...);
}

auto sortByArea(std::shared_ptr<Shape> first, std::shared_ptr<Shape> second)
{
    return [](std::shared_ptr<Shape> first, std::shared_ptr<Shape> second)
    {
        if(first == nullptr || second == nullptr)
        {
            return false;
        }
            
        return (first->getArea() < second->getArea());
    };
}

auto perimeterBiggerThan20(std::shared_ptr<Shape> s)
{
    return [](const std::shared_ptr<Shape>& s)
    {
        if(s)
        {
            return (s->getPerimeter() > 20);
        }
        return false;
    };
}

auto areaLessThanX(const int & value)
{
    return [&value](std::shared_ptr<Shape> s)
    {
        if(s)
        {
            return (s->getArea() < value);
        }
        return false;
    };
}

void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
        {
            it->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for(auto it : collection)
    {
        if(it != nullptr)
        {
            std::cout << it->getArea() << std::endl;
        }
    }
}

template<class Predicate>
void findFirstShapeMatchingPredicate(const Collection& collection,
                                     Predicate predicate,
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        std::cout << "First shape matching predicate: " << info << std::endl;
        (*iter)->print();
    }
    else
    {
        std::cout << "There is no shape matching predicate " << info << std::endl;
    }
}

constexpr int Fibonacci(unsigned int fibNumber) 
{
    if(fibNumber == 0) {
        return 1;
    }
    if(fibNumber <= 2) {
        return 1;
    }
    return Fibonacci(fibNumber - 1) + Fibonacci(fibNumber - 2);
}

int main()
{
    std::cout << "alignment " << alignof(Circle) << std::endl;

    auto uptr = std::make_unique<Circle>(5.0);

    Collection shapes = {
        std::shared_ptr<Circle>(new Circle(2.0)),
        std::shared_ptr<Circle>(new Circle(3.0)),
        nullptr,
        std::move(uptr),
        std::shared_ptr<Circle>(new Circle(4.0)),
        std::shared_ptr<Rectangle>(new Rectangle(10.0, 5.0)),
        std::shared_ptr<Square>(new Square(3.0)),
        std::shared_ptr<Circle>(new Circle(4.0)),
        make_shape<Rectangle>(12.0, 6.0)
    
    };

    printCollectionElements(shapes);

    std::cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    std::cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = std::shared_ptr<Circle>(new Circle(4.0));
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX(10), "area less than 10");
    

    //std::cout << Fibonacci(45) << std::endl;

    /*
    no constexpr
    real    0m14,079s
    user    0m13,939s
    sys     0m0,060s
    
    constexpr - before function declaration
    real    0m0,003s
    user    0m0,003s
    sys     0m0,000s
    
    */

    return 0;
}

