#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

//11 SFINAE
template <typename T, typename = typename std::enable_if<std::is_base_of<Shape, T>::value, T>::type>
void insert(shared_ptr<T>&& arg, Collection& collection)
{
    collection.push_back(arg);
}

//18 variadic templates
template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return make_shared<DerivedType>(args ...);
}

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args);


void printCollection(const Collection& collection)
{
    for (const auto& it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for (const auto& it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

//16 Lambda
void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibo(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int main()
{
    constexpr int n = fibo(45);
    Collection shapes{
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };

    shapes.push_back(make_shape<Circle>(300));
    shapes.push_back(make_shape<Rectangle>(300, 10));

    printCollection(shapes);

    Circle c1{Color::Green};
    // auto pi = c1.getPi();
    Rectangle r1{Color::Black};
    // Square s1{};
    auto values = {1, 2, 3, 4, 5};
    // std::cout << values[2];

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
        if (first == nullptr || second == nullptr)
        {
            return false;
        }
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    insert(move(square), shapes);
    insert(make_shared<Circle>(4.0), shapes);

    //16 Lambda
    findFirstShapeMatchingPredicate(
        shapes,
        [&](shared_ptr<Shape> s) {
            if (s)
            {
                return (s->getPerimeter() > 20);
            }
            return false;
        },
        "perimeter bigger than 20");

    //16 Lambda
    auto areaLessThanX = [x = 10](shared_ptr<Shape> s) {
        if (s)
        {
            return (s->getArea() < x);
        }
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    //14 Alignof, alignas
    cout << "Alignment of" << '\n' << "Circle: " << alignof(Circle) << '\n';

    map<shared_ptr<Shape>, double> database{};
    for (const auto shape : shapes)
    {
        if (shape)
        {
            database.insert(make_pair(shape, shape->getPerimeter()));
        }
    }
    //17 Structured bindings
    for (const auto& [key, value] : database)
    {
        cout << "Shape : ";
        key->print();
        cout << "Perimeter : " << value << " \n";
    }


    return 0;
}
