#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>
#include <type_traits>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;
using mapCollection = map<shared_ptr<Shape>, double>;
using shapePtr = shared_ptr<Shape>;


auto sortByArea = [](shapePtr first, shapePtr second) {
    if(first == nullptr || second == nullptr) { return false; }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shapePtr s) {
    if (s) { return (s->getPerimeter() > 20); }
    return false;
};

auto areaLessThanX = [x = 10](shapePtr s) {
    if (s) { return s->getArea() < 10; }
    return false;
};

void printCollectionElements(const Collection& collection)
{
    for (const auto& it: collection) {
        if(it) {
            (it)->print();
        }
    }
}

void printMapCollectionElements(const mapCollection& collection)
{
    for (const auto& [key, value]: collection) {
        if(key) {
            (key)->print();
        }
    }
}

void printAreas(const Collection& collection)
{
    for (const auto& it: collection) {
        if(it) {
            cout << (it)->getArea() << endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shapePtr)> predicate,
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

int constexpr fibo(int number)
{
    if (number <= 2) { return 1; }
    return fibo(number - 1) + fibo(number - 2);
}

template <typename T, typename = typename std::enable_if_t<std::is_base_of<Shape, T>::value>>
void insertToCollection(Collection& collection, std::shared_ptr<T> shape) {
    collection.push_back(shape);
}

template<class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args) {
    return make_shared<DerivedType>(std::forward<Arguments>(args)...);
}

int main()
{
    // int a = fibo(45);
    Collection shapes;

    insertToCollection(shapes, make_shape<Circle>(2.0));
    shapes.push_back(make_shape<Circle>(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(make_shape<Circle>(4.0));
    shapes.push_back(make_shape<Rectangle>(10.0, 5.0));
    shapes.push_back(make_shape<Square>(3.0));
    shapes.push_back(make_shape<Circle>(4.0));
    printCollectionElements(shapes);


    mapCollection mapCollect;
    transform(shapes.begin(), shapes.end(),
        inserter(mapCollect, mapCollect.begin()),
        [](const shapePtr& sp) {
            return sp ? make_pair(sp, sp->getPerimeter()) : make_pair(nullptr, 0.0);

    });
    cout << "Collection as map: " << std::endl;
    printMapCollectionElements(mapCollect);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    insertToCollection(shapes, make_shared<Square>(4.0));

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    std::cout << "Alignment of Circle " << alignof(Circle) << '\n';

    return 0;
}
