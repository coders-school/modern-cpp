#include <iostream>
#include <vector>
#include <algorithm>
#include <any>
#include <string>
#include <map>
#include <functional>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection& collection)
{
    for (auto&& it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for (const auto& it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

// using Predicate = bool (*)(shared_ptr<Shape>);
using Predicate = std::function<bool(shared_ptr<Shape>)>;

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

constexpr int fibonacci(int number)
{
    if (number < 2) {
        return 1;
    }
    return fibonacci(number - 1) + fibonacci(number - 2);
}

struct alignas(16) see_t {
    float see_data[4];
};

// aliagnas(2) int a;
    
// | char |      |      |      | int                   |
// 0      1      2      3      4     5     6     7     8

template <typename Sh, typename... Args>
shared_ptr<Shape> make_shape(Args&&... args) {
    return make_shared<Sh>(args...);
    // make_shared<Sh>(arg1, arg2, ..., argN)
}

int main()
{
    std::any x {5};
    cout << std::any_cast<int>(x) << endl;
    x = std::string{"string"};

    cout << std::any_cast<std::string>(x) << endl;
    try {
        auto y = std::any_cast<int>(x);
        cout << y << endl;
    } catch (const std::bad_any_cast & bac) {
        cout << "it's not an int!\n";
    }

    cout << alignof(Circle) << endl;
    // int a = 10;
    // static_assert(alignof(Shape) == 8);
    // decltype(std::declval<Shape>().getArea()) xyz = 3.0;
    // cout << xyz << endl;

    constexpr int result = fibonacci(45);
    cout << result << endl;

    auto circle = make_shape<Circle>(Color::Yellow);
    auto rect = make_shape<Rectangle>(Color::Green);
    auto sq = make_shape<Square>(Color::Yellow);

    Collection shapes {
        make_shape<Circle>(3.0),
        make_shape<Circle>(2.0),
        // nullptr,
        make_shape<Circle>(4.0),
        make_shape<Rectangle>(10.0, 5.0),
        make_shape<Square>(3.0),
        make_shape<Circle>(4.0),
        circle, 
        rect,
        sq
    };
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(),
              shapes.end(),
              [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
                  if(first == nullptr || second == nullptr)
                      return false;
                  return (first->getArea() < second->getArea());
              });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");

    auto areaLessThanX = [x = 10](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getArea() < x);
        return false;
    };
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    std::map<shared_ptr<Shape>, double> perimeters;
    // for (auto && el : shapes) {
    //     if (el) {
    //         perimeters.insert(std::make_pair(el, el->getPerimeter()));
    //     }
    // }
    std::transform(shapes.begin(),
               shapes.end(),
               std::inserter(perimeters, perimeters.end()),
               [](auto el){
                    return std::make_pair(el, el->getPerimeter());
               });

    for (auto && [key, value] : perimeters) {
        key->print();
        cout << ", perimeter: " << value << endl;
    }
    std::vector v = {1, 2, 3, 4};

    return 0;
}
