#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

bool sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(shared_ptr<Shape> s) {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
}

bool areaLessThan10(shared_ptr<Shape> s) {
    if (s)
        return (s->getArea() < 10);
    return false;
}

void printCollectionElements(const Collection& collection) {
    for (const auto& it : collection)
        if (it)
            it->print();
}

void printAreas(const Collection& collection) {
    for (const auto& it : collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
                                     std::string info) {
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

template<typename T, typename = typename std::enable_if<std::is_base_of<Shape, T>::value>>
void collectionInsert(Collection& collection, std::shared_ptr<T>& shape){
    collection.emplace_back(shape);
}


int main() {
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

//Exercise 11 CHECK
    auto circleAdd = std::make_shared<Circle>(5);
    collectionInsert(shapes, circleAdd);
    printCollectionElements(shapes);
//Exercise 11 NOT WORKING EXAMPLE
    //auto test = std::make_shared<int>(10);
    //collectionInsert(shapes, test);


//EXERCISE 14 CHECK
    std::cout << "Circle Align " << alignof(Circle) << '\n';

    return 0;
}
