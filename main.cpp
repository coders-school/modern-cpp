#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <memory>

using namespace std;

//typedef vector<Shape*> Collection;        //zad3
using Collection = vector<Shape*> ;          //zad3

auto sortByArea = [] (Shape* first, Shape* second)
                    { if(first == nullptr || second == nullptr)return false;
                    return (first->getArea() < second->getArea());};

auto perimeterBiggerThan20 = [](Shape* s)
                             {if(s) return (s->getPerimeter() > 20);
                             return false;};

auto areaLessThan10= [](Shape* s)
                     {if(s) return (s->getArea() < 10);
                     return false;};

auto areaLessThanX= [](int x = 10, Shape* s)        //<-- shoule be int x = 10 declarated here?
                     {if(s) return (s->getArea() < x);
                     return false;};

void printCollectionElements(const Collection& collection)
{
    for(auto it : collection)   //zad6
    {
        if(it != nullptr)
        {
            (it)->print();
        }
    }
}

void printAreas(const Collection& collection)
{

    for(auto it : collection)   //zad6
    {
        if(it != nullptr)
        {
            cout << (it)->getArea() << std::endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(Shape* s),
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

constexpr size_t FibonacciNumber (int number) //zad 11
{
    if(number == 1 or number == 2)
        return 1;
    else
        return FibonacciNumber(number-1)+ FibonacciNumber(number-2);
}


int main()
{
    std::cout<<FibonacciNumber(45)<<std::endl;

    Circle obj(10);
    std::cout<<"Alignof Circle: "<<alignof(obj)<<std::endl;
    Circle new_obj(std::shared_ptr<Circle> obj);
    Collection shapes = {new Circle(2.0), 
                        // std::shared_ptr<Circle> (new double(2.0)),  <-- cam I use it in construcotr?
                         new Circle(3.0), 
                         nullptr, 
                         new Circle(4.0), 
                         new Rectangle(10.0, 5.0), 
                         new Square(3.0), 
                         new Circle(4.0)};

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    Square* square = new Square(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    return 0;
}

