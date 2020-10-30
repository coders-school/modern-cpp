#include <cassert>
#include <coroutine>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>

template <typename Promise = void>
struct coroutine_handle;

template <>
struct coroutine_handle<void> {
    constexpr coroutine_handle() noexcept;
    constexpr coroutine_handle(nullptr_t) noexcept;
    coroutine_handle& operator=(nullptr_t) noexcept;
    constexpr void* address() const noexcept;
    constexpr static coroutine_handle from_address(void* addr);
    constexpr explicit operator bool() const noexcept;
    bool done() const;
    void operator()();
    void resume();
    void destroy();

private:
    void* ptr;  // exposition only
};

class resumable {
public:
    struct promise_type;
    using coro_handle = std::coroutine_handle<promise_type>;

    resumable(coro_handle handle)
        : handle_(handle) { assert(handle); }
    resumable(resumable&) = delete;
    resumable(resumable&&) = delete;

    unsigned long long operator()() {
        if (resume()) {
            return factorial();
        }
        return 0ull;
    }

    bool resume() {
        if (not handle_.done()) {
            handle_.resume();
        }
        return not handle_.done();
    }
    ~resumable() { handle_.destroy(); }
    // const char* recent_val();
    unsigned long long factorial();

private:
    coro_handle handle_;
};

struct resumable::promise_type {
    using coro_handle = std::coroutine_handle<promise_type>;
    auto get_return_object() {
        return coro_handle::from_promise(*this);
    }
    auto initial_suspend() { return std::suspend_always(); }
    auto final_suspend() { return std::suspend_always(); }
    void return_void() {}
    void unhandled_exception() {
        std::terminate();
    }

    // const char* string_ = nullptr;
    unsigned long long fact_ = 1ull;

    auto yield_value(unsigned long long n) {
        fact_ *= n;
        return std::suspend_always();
    }
};

// const char* resumable::recent_val() { return handle_.promise().string_; }
unsigned long long resumable::factorial() {
    return handle_.promise().fact_;
}

// resumable foo(){
//   while(true){
//     co_yield "Hello";
//     co_yeild "Coroutine";
//   }
// }

// resumable foo(){
//     std::cout << "Hello" << std::endl;
//     co_await std::suspend_always();
//     std::cout << "Coroutine" << std::endl;
// }

resumable foo() {
    unsigned long long i = 1;
    while (true) {
        co_yield i++;
    }
}

struct Point2D {
    int x = 0;
    int y = 0;

    bool operator==(Point2D other);
    bool operator!=(Point2D other);
    bool operator<(Point2D other);
    bool operator>(Point2D other);
    bool operator<=(Point2D other);
    bool operator>=(Point2D other);

    int operator<=>(const Point2D & other) const = default;
};

int main() {
    resumable res = foo();

    std::vector<unsigned long long> collection;

    std::generate_n(std::back_inserter(collection), 50, std::ref(res));

    for (auto && el : collection) {
        std::cout << el << '\n';
    }

    return 0;
}
