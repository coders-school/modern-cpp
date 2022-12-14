#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <map>
#include <functional>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for (auto it : collection) {
        if(it) {
            it->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for (auto it : collection) {
        if (it) {
            cout << it->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                    //  bool (*predicate)(shared_ptr<Shape> s),
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

// char a;
// alignas(int) char b;
// int c;
// char d;

// a       b       c       d
// 0 1 2 3 4 5 6 7 8



constexpr int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    std::cout << alignof(Circle) << '\n';

    constexpr int result = fib(45);
    std::cout << result << '\n';

    // std::vector<int> v1{1, 2}; // 1, 2
    // std::vector<int> v1 = {1, 2}; // 1, 2
    // std::vector<int> v2(1, 2); // 2

    Collection shapes = {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
        make_shared<Circle>(Color::Blue),
        make_shared<Rectangle>(Color::Green),
        make_shared<Square>(Color::Red),
    };
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](auto first, auto second)
    {
        if(first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);
    // square->getY();
    // auto sq = make_shared<Square>(1.0);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");

    auto areaLessThanX = [x = 10](shared_ptr<Shape> s) {
        if(s)
            return (s->getArea() < x);
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    auto rect = make_shared<Rectangle>(Color::Green);
    auto rect2 = rect;
    rect2->print();

    std::cout << "alignment of Square: " << alignof(decltype(*rect)) << '\n';

    std::map<shared_ptr<Shape>, double> perimeterMap;
    std::transform(shapes.begin(), shapes.end(), std::inserter(perimeterMap, perimeterMap.begin()),
        [](auto el){
            return std::make_pair(el, el ? el->getPerimeter() : 0);
            // return std::pair<std::shared_ptr<Shape>, double>(el, el ? el->getPerimeter() : 0);
        }
    );
    // for (const auto & element : shapes) {
    //     if (element) {
    //         perimeterMap.insert(std::make_pair(element, element->getPerimeter()));
    //     }
    // }

    for (const auto & [key, value] : perimeterMap) {
        if (key) {
            key->print();
            std::cout << "perimeter: " << value << '\n';
        }
    }

    return 0;
}
