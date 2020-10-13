#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;
using shapePtr = shared_ptr<Shape>;

auto sortByArea = [](shapePtr first, shapePtr second) {
    if(first == nullptr || second == nullptr) { return false; }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shapePtr s) {
    if (s) { return (s->getPerimeter() > 20); }
    return false;
};

auto areaLessThan10 = [](shapePtr s) {
    if (s) { return s->getArea() < 10; }
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for (const auto& it: collection)
        if(it)
            (it)->print();
}

void printAreas(const Collection& collection)
{
    // for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
    for (const auto& it: collection)
        if(it)
            cout << (it)->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
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

int constexpr fibo(int number)
{
    if (number <= 2) { return 1; }
    else { return fibo(number - 1) + fibo(number - 2); }
}

int main()
{
    // int a = fibo(45);
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

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    std::cout << "Alignment of Circle " << alignof(Circle) << '\n';

    return 0;
}

