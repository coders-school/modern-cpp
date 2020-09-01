#include <utility>
#include <iostream>

template <typename T>
class X {
    T* ptr {};
public:
    X(T* p) : ptr(p) {}
    ~X() { 
        delete ptr;
    }
    X(const X & other) : ptr(new T{*other.ptr}) {}
    X& operator=(const X & other) {
        delete ptr;
        ptr = new T{*other.ptr};
        return *this;
    }
    X(X && other) : ptr(other.ptr) {
        other.ptr = nullptr;
    }
    X& operator=(X && other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
    T& get() {
        return *ptr;
    }
};

int main() {
    X<int> x{new int{42}};
    X<int> x2{new int{42}};
    X<int> x3 = x;      // copy constructor
    x2 = x;             // copy assignment
    X<int> x4{std::move(x2)};
    x3 = std::move(x);
    std::cout << x4.get();
    return 0;
}