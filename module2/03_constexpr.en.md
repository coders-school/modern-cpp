<!-- .slide: data-background="#111111" -->
# `constexpr`

___

## `constexpr` keyword

**Rationale**: faster runtime binary by moving some computations at compile-time.

`constexpr` is an expression that can be evaluated at compile time and can appear in [constant expressions](https://en.cppreference.com/w/cpp/language/constant_expression). We can have:

* <!-- .element: class="fragment fade-in" --> constexpr variables
* <!-- .element: class="fragment fade-in" --> constexpr functions
  * <!-- .element: class="fragment fade-in" --> normal constexpr functions
  * <!-- .element: class="fragment fade-in" --> constexpr constructors
  * <!-- .element: class="fragment fade-in" --> constexpr lambdas (default from C++17)
  * <!-- .element: class="fragment fade-in" --> constexpr destructor (from C++20)
* <!-- .element: class="fragment fade-in" --> constexpr if (from C++17)

___

## `constexpr` variables

```cpp
int a = 10;             // variable
const int b = 20;       // constant
const double c = 20;    // constant
constexpr int d = 30;   // constant at compile-time

constexpr auto e = a;   // error: initializer is not a constant expression
constexpr auto f = b;   // OK for integral, C++03 compatibility exception
constexpr auto g = c;   // error: initializer is not a constant expression
constexpr auto h = d;   // OK
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>constexpr</code> variable must be initialized immediately with constant expression. <code>const</code> does not need to be initialized with constant expression.
* <!-- .element: class="fragment fade-in" --> <code>constexpr</code> variable must be a <a href="https://en.cppreference.com/w/cpp/named_req/LiteralType">LiteralType</a>

___

## `constexpr` functions

```cpp
constexpr int factorial11(int n) {  // C++11 compatible
{
    return (n == 0) ? 1 : n * factorial11(n-1);
}

constexpr int factorial14(int n) {  // C++14
    if (n == 0) {
        return 1;
    } else {
        return n * factorial14(n-1);
    }
}
```

`constexpr` function can be evaluated in both compile time and runtime. Evaluation at compile time must occur when the result is assigned to `constexpr` variable. Arguments must be known at compile time.
<!-- .element: class="fragment fade-in" -->

___

## `constexpr` functions restrictions

In C++11 `constexpr` functions were very restricted - only 1 return instruction (not returning void). From C++17 the only restrictions are, that function must not:

* <!-- .element: class="fragment fade-in" --> contain <code>static</code> or <code>thread_local</code> variables
* <!-- .element: class="fragment fade-in" --> contain uninitialized variables
* <!-- .element: class="fragment fade-in" --> call non <code>constexpr</code> function
* <!-- .element: class="fragment fade-in" --> be virtual (until C++20)
* <!-- .element: class="fragment fade-in" --> have try-catch block (until C++20)
* <!-- .element: class="fragment fade-in" --> be a coroutine (from C++20)

More info on [cppreference.com](https://en.cppreference.com/w/cpp/language/constexpr).
<!-- .element: class="fragment fade-in" -->

___

## `constexpr` constructor

```cpp
struct Point
{
    constexpr Point(int x, int y)
        : x_(x), y_(y)
    {}

    int x_;
    int y_;
};

constexpr Point a = { 1, 2 };
```

Class `Point` can be used in `constexpr` computations, eg in `constexpr` functions.

`constexpr` constructor has the same restrictions as a `constexpr` function and a class cannot have a virtual base class.

___

## `constexpr` lambda

From C++17 all lambda functions are by default implicitly marked as `constexpr`, if possible. `constexpr` keyword can also be used explicitly.

```cpp
auto squared = [](auto x) {             // implicitly constexpr
    return x * x;
};

std::array<int, squared(8)> a;          // OK - array<int, 64>

auto squared = [](auto x) constexpr {   // OK
    return x * x;
};
```

___

## `constexpr if`

```cpp
if constexpr (a < 0)
    doThis();
else if constexpr (a > 0)
    doThat();
else
    doSomethingElse();
```

`constexpr if` selects only one block of instructions, depending on which condition is met. The condition and other blocks are not compiled in the binary. The condition must be a constant expression.

___

## `constexpr if` in SFINAE

`constexpr if` allows a simplification of template code used by SFINAE idiom.

```cpp
template<class T>;   // C++17
auto compute(T x) {
    if constexpr(std::is_scalar_v<T>) {
        return singleComputation(x);
    } else {
        return multipleComputation(x);
    }
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template<class T>;   // C++11
auto compute(T x) -> enable_if<std::is_scalar<T>::value, int>::type {
    return singleComputation(x);
}
template<class T>
auto compute(T x) -> enable_if<!std::is_scalar<T>::value, int>::type {
    return multipleComputation(x);
}
```
<!-- .element: class="fragment fade-in" -->

___

## Exercise

Write a function that calculates n-th Fibonacci's number. Do not mark it `constexpr`.

In the first line of `main()` add computing 45-th Fibonacci's number. Measure the time of program execution (`time ./modern_cpp`)

Mark fibonacci function as `constexpr`, compile the program and measure the time of execution once again.

If you can't see a big difference assign the result to the constexpr variable.
