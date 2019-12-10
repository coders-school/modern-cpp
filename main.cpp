#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <functional>

#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <map>

using namespace std;

typedef vector<shared_ptr<Shape>> Collection;


void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            (*it)->print();
}

void printAreas(const Collection& collection)
{
    for(vector<shared_ptr<Shape>>::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            cout << (*it)->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape> s)> predicate,
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

int main()
{
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

    std::sort(shapes.begin(), shapes.end(), [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
        if (first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(
		shapes, 
		[](shared_ptr<Shape> s) {
		    if (s)
			    return (s->getPerimeter() > 20);
		    return false;
	    }, 
		"perimeter bigger than 20");

    findFirstShapeMatchingPredicate(
		shapes, 
		[x = 10](shared_ptr<Shape> s)
		{
			if (s)
				return (s->getArea() < x);
			return false;
		},
		"area less than 10");

	cout << "alignof(Circle): " << alignof(Circle) << endl;

	auto shape = make_shape<Circle>(10, Color::Green);
	shape->print();

    return 0;
}

