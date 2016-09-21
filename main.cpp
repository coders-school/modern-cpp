#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <thread>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

typedef vector<Shape*> Collection;

bool sortByArea(Shape* first, Shape* second)
{
    if(first == NULL || second == NULL)
    {
        return false;
    }
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(Shape* s)
{
    if(s)
    {
        return (s->getPerimeter() > 20);
    }
    return false;
}

bool areaLessThan10(Shape* s)
{
    if(s)
    {
        return (s->getArea() < 10);
    }
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if(*it != NULL)
        {
            (*it)->print();
        }
    }
}

void printArea(std::string name, double area)
{
    std::cout << "thread_id: " << std::this_thread::get_id() << " - " << name << ": " << area << std::endl;
}

void printAreas(const Collection& collection)
{
    std::vector<std::thread> threads;
    for(vector<Shape*>::const_iterator it = collection.begin(); it != collection.end(); ++it)
    {
        if(*it != NULL)
        {
            std::thread th(printArea, (*it)->getName(), (*it)->getArea());
            threads.push_back(std::move(th));
        }
    }
    for(unsigned int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(Shape* s),
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != NULL)
    {
        cout << std::endl << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << std::endl << "There is no shape matching predicate " << info << endl;
    }
}


class BlockingQueue
{
public:
    BlockingQueue() = default;

    void push(Shape* shape)
    {
        // TODO
    }

    Shape* pop()
    {
        // TODO
        return NULL;
    }
};

BlockingQueue g_queue;

void runQueue()
{
    bool running = true;
    while(running)
    {
        Shape * shape = g_queue.pop();
        if(shape == NULL)
        {
            std::cout << "Queue received NULL, finishing loop" << std::endl;
            break;
        }
        else
        {
            std::cout << "Shape on queue: " << shape->getName() << std::endl;
        }
    }
}

void pushShapesToQueue(Collection const& shapes)
{
    for(int i = 0; i < shapes.size(); ++i)
    {
        g_queue.push(shapes[i]);
    }
}

int main()
{
    Collection shapes;
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Circle(3.0));
    shapes.push_back(NULL);
    shapes.push_back(new Circle(4.0));
    shapes.push_back(new Rectangle(10.0, 5.0));
    shapes.push_back(new Square(3.0));
    shapes.push_back(new Circle(4.0));

    printCollectionElements(shapes);

    cout << std::endl << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << std::endl << "Areas after sort: " << std::endl;
    printAreas(shapes);

    Square* square = new Square(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    std::thread queueThread(runQueue);
    pushShapesToQueue(shapes);

    queueThread.join();

    return 0;
}

