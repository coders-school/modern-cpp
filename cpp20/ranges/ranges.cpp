#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>


int main() {
    std::vector<int> ints{1, 23, 54, 35, 43, 2, 342, 4, 44};
    std::vector<int> other{0, 23, 44, 666, 22222};
    auto even = [](int i){ return 0 == i % 2; };
    auto square = [](int i) { return i * i; };

    for (int i : ints | std::views::take(4) | std::views::transform(square)) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    using namespace std::ranges;

    sort(ints);
    for (int i : ints | std::views::common) {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
}
