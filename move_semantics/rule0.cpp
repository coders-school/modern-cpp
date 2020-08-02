#include <memory>
#include <iostream>

template <typename T>
class X {
    std::shared_ptr<T> ptr {};
public:
    X(T* p) : ptr(p) {}
    X(std::shared_ptr<T> p) : ptr(p) {}
    T& get() {
        return *ptr;
    }
};

int main() {
    X<int> x{new int{42}};
    X<int> x2{new int{42}};
    X<int> x3 = x;      // copy constructor
    x2 = x;             // copy assignment
    // X<int> x4{std::move(x2)};
    // x3 = std::move(x);
    auto & a = x.get();
    a++;
    std::cout << x3.get();
    std::cout << x2.get();
    std::cout << x.get();
    return 0;
}