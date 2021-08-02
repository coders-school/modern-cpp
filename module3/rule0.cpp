#include <memory>
#include <iostream>
#include <utility>

template <typename T>
T take(T&& a) {
    return a;
}

// int take(const int & a) {
//     return a;
// }

int main() {
    take(5);
    const int i = 10;
    const int & ref = i;
    take(std::move(ref));
    take(i);
    // take(ref);
    return 0;
}