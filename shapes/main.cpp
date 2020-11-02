#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

//TASK #11
template <class DerivedType>
using SFINAE = std::enable_if<std::is_base_of<Shape, std::remove_reference_t<DerivedType>>::value>;

template <class DerivedType, class = SFINAE<DerivedType>>
auto insertSubclassOfShapes(Collection& collection, const std::shared_ptr<DerivedType>& shape)
{
    auto whereWasInserted = collection.emplace_back(shape);
    return whereWasInserted;
}

//TASK #16
auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) -> bool {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) -> bool {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s) -> bool {
    if (s)
        return (s->getArea() < x);
    return false;
};

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

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

//TASK #18
template <class DerivedType, class... Arguments>
std::shared_ptr<Shape> make_shape(Arguments&&... args)
{
    return std::make_shared<DerivedType>(std::forward<Arguments>(args)...);
}

int main()
{
    Collection shapes{
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };
    printCollection(shapes);

    //TASK #14
    std::cout << "TASK #14\n";
    std::cout << alignof(Circle) << "\n";
    //for alignas(128) is set correctly, but when alignas(2), is set as 8 baits -> i think it's because of double r_ class member

    //TASK #15
    std::cout << "TASK #15\n";
    std::cout << "Rectangle\n";
    Rectangle randomRectangle(1.0, 9.0);
    randomRectangle.getColor();
    Rectangle randomRectangle2(1.0, 9.0, Color::Green);
    randomRectangle2.getColor();
    std::cout << "Square\n";
    Square randomSquare(88.9);
    randomSquare.getColor();
    Square randomSquare2(1.0, Color::Black);
    randomSquare2.getColor();
    std::cout << "Circle\n";
    Circle randomCircle(88.9);
    randomCircle.getColor();
    Circle randomCircle2(1.0, Color::Green);
    randomCircle2.getColor();

    Circle c1{Color::Green};
    // auto pi = c1.getPi();
    Rectangle r1{Color::Black};
    // Square s1{};
    auto values = {1, 2, 3, 4, 5};
    // std::cout << values[2];

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    //TASK #16
    std::cout << "TASK #16\n";
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than x");

    //TASK #17
    std::cout << "TASK #17\n";
    using ShapesWithPerimeterHolder = std::map<shared_ptr<Shape>, double>;

    ShapesWithPerimeterHolder shapesAndPerimeters{};

    std::transform(shapes.cbegin(), shapes.cend(), std::inserter(shapesAndPerimeters, shapesAndPerimeters.begin()),
                   [](const shared_ptr<Shape>& everyShape) {
                       if (everyShape) {
                           return std::make_pair(everyShape, everyShape->getPerimeter());
                       }
                       return std::make_pair(everyShape, 0.0);
                   });

    for (const auto& [shape, perimeter] : shapesAndPerimeters) {
        if (shape) {
            shape->print();
        }
        std::cout << perimeter << "\n";
    }

    //TASK #18
    std::cout << "TASK #18\n";
    auto fastSquare = make_shape<Square>(20.7);
    auto fastCircle = make_shape<Circle>(4, Color::Black);
    auto fastRectangle = make_shape<Rectangle>(44.4, 20.7, Color::Green);
    fastSquare->getColor();
    fastCircle->getColor();
    fastRectangle->getColor();

    //TASK #11
    std::cout << "TASK #11\n";
    auto insertedIn = insertSubclassOfShapes<Rectangle>(shapes, std::make_shared<Rectangle>(50, 40, Color::Black));
    insertedIn->getColor();
    auto insertedIn2 = insertSubclassOfShapes<Square>(shapes, std::make_shared<Square>(1000, Color::Green));
    insertedIn2->getColor();
    auto insertedIn3 = insertSubclassOfShapes<Circle>(shapes, std::make_shared<Circle>(2));
    insertedIn3->getColor();
    return 0;
}
