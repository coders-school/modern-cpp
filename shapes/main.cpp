#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollection(const Collection& collection)
{
    for (const auto & it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection)
{
    for (const auto & it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
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

constexpr int fibo(int n) {
    if (n<=2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return make_shared<DerivedType>(std::forward<decltype(args)>(args)...);
}

template <typename T, typename = typename std::enable_if<std::is_base_of_v<Shape, T>>>
void shapesCollectionInsert(Collection& collection, std::shared_ptr<T>& shape) {
    collection.emplace_back(shape);
}

int main()
{
    constexpr int n = fibo(45);
    Collection shapes {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };
    printCollection(shapes);

    Circle c1{Color::Green};
    // auto pi = c1.getPi();
    Rectangle r1{Color::Black};
    // Square s1{};
    auto values = {1, 2, 3, 4, 5};
    // std::cout << values[2];

    cout << "Alignment of" << '\n'
         << "Circle: " << alignof(Circle) << '\n';
         //When alignas set to 2 then warning appears "alignment cannot be set to less than the default alignment"
         //and result in 8-alignment

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
        if (first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    };
    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) {
        if (s)
            return (s->getPerimeter() > 20);
        return false;
    };

    auto areaLessThanX = [x = 10](shared_ptr<Shape> s) {
        if (s)
            return (s->getArea() < x);
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    std::map<shared_ptr<Shape>, double> shapesWithPerimeters;
    for (auto shape : shapes) {
        if (shape != nullptr) {
            shapesWithPerimeters.insert({shape, shape->getPerimeter()});
        }
    }

    for (const auto& [shape, perim] : shapesWithPerimeters) {
        cout << "\n--------------\nPERIMETER: "<< perim << '\n';
        if (shape) {
            shape->print();
        }
        cout << '\n';
    }

    auto shape_rec = make_shape<Rectangle>(666, 222);
    shape_rec->print();
    auto shape_cir = make_shape<Circle>(555);
    shape_cir->print();

    std::cout << "\n\n SFINAE - ok\n";
    shapesCollectionInsert(shapes, shape_rec);
    printCollection(shapes);

    std::cout << "\n\n SFINAE - nok - not allowed\n";
    auto invalidShape = std::make_shared<double>(15.0);
    // shapesCollectionInsert(shapes, invalidShape);

    return 0;
}
