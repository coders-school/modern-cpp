#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

bool sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
}

bool areaLessThan10(shared_ptr<Shape> s)
{
    if(s)
        return (s->getArea() < 10);
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(auto it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            (*it)->print();
}

void printAreas(const Collection& collection)
{
    for(auto const & it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
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

template <class T>
class our_ptr
{
private:
    our_ptr() = delete;
    our_ptr(const our_ptr<T>& p) = delete;
    our_ptr<T>& operator=(const our_ptr<T> &ptr) = delete;

    T *ptr = nullptr;
public:
    explicit our_ptr(T* p) {
        ptr = p;
    }
    ~our_ptr() {
        cout << "gine" << endl;
        delete ptr;
    }
    
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }

    our_ptr (our_ptr<T>&&p) {
        delete ptr;
        ptr = p.ptr;
        p.ptr =  nullptr;
    }
    our_ptr<T>& operator=(our_ptr<T>&&p) {
        delete ptr;
        ptr = p.ptr;
        p.ptr =  nullptr;
        return *this;
    }

    T& operator* () {
        return *ptr;
    }

    T* get() {
        return ptr;
    }

    T* operator->() {
        return get();
    }

};

constexpr int fibo(int n) {
    if (n <= 2) 
        return 1;
    return fibo(n-1) + fibo(n-2);
}

template <typename T,
          typename = std::enable_if_t<std::is_base_of_v<Shape, T>>
>
void insert(T item, Collection& collection) {
    collection.emplace_back(make_shared<T>(item));
}

void our_ptr_usages() {
    our_ptr<Shape> our_shape(new Circle(123.0));
    our_ptr<int> our_int(new int(1));
    cout << *our_int << endl;
    our_ptr<int> p2 = std::move(our_int);
    cout << *p2 << endl;
    *p2 = 10;
    cout << *p2 << endl;
    cout << our_shape->getArea() << endl;
    our_ptr<int> p3(new int(1));
    p3 = move( p2);
    *p2;
    cout << *p3 << endl;

    // our_ptr<int> p5(p3);

    cout << our_shape.get() << endl;
    cout << our_shape.get()->getArea() << endl;

    p3.reset();

    p2.reset(new int(2));

    cout << *p2 << endl;
}

//    cout << *our_int << endl;

int main()
{
    // constexpr int result = fibo(45);
    // std::cout << result << std::endl;

    Collection shapes = {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
    };
    printCollectionElements(shapes);

    Square a{50.0};
    insert(a, shapes);
    // insert(4, shapes); - not allowed

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);
    std::sort(shapes.begin(), shapes.end(), sortByArea);
    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    Square s{3.0};
    Square r = std::move(s);

    Rectangle d{Color::red};
    Square f{Color::blue};

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    return 0;
}
