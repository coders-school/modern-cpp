#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first || second)
        return false;
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
}

bool areaLessThan10(shared_ptr<Shape> s)
{
    if(s)
        return (s->getArea() < 10);
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(const auto& it : collection)
        if(it)
            (it)->print();
}

void printAreas(const Collection& collection)
{
    for(const auto& element : collection)
        if (element)
            std::cout << element->getArea() << std::endl;
}

auto findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        std::cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        std::cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    int array[] = {1, 2, 3};
    for (auto element : array) {
        std::cout << element;
    }

    auto c = Colour::Blue;
    auto d = static_cast<int>(c);
    d++;
    c = static_cast<Colour>(d);

    auto values = {1, 2, 3, 4, 5, 1, 30};

    Collection shapes{
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };

    Circle c2{Colour::Red};
    Rectangle r2{Colour::Green};
    Square s2{Colour::Blue};
    auto c3 = c2;

    // Rectangle r3{};

    printCollectionElements(shapes);

    std::cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    std::cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    return 0;
}
