<!-- .slide: data-background="#111111" -->
# `constexpr`

___

## `constexpr` keyword

<p><strong>Rationale</strong>: faster runtime binary by moving some computations at compile-time.</p>
<p><code>constexpr</code> is an expression that can be evaluated at compile time and can appear in <a href="https://en.cppreference.com/w/cpp/language/constant_expression">constant expressions</a>. We can have:</p>

* <!-- .element: class="fragment fade-in" --> constexpr variable
* <!-- .element: class="fragment fade-in" --> constexpr function
* <!-- .element: class="fragment fade-in" --> constexpr constructor
* <!-- .element: class="fragment fade-in" --> constexpr lambda (default from C++17)
* <!-- .element: class="fragment fade-in" --> constexpr if (until C++17)

___

## `constexpr` variables

```cpp
int a = 10;             // variable
const int b = 20;       // constant
const double c = 20;    // constant
constexpr int d = 30;   // constant at compile-time

constexpr auto e = a;   // error: initializer is not a contant expression
constexpr auto f = b;   // OK for integral, C++03 compatibility exception
constexpr auto g = c;   // error: initializer is not a contant expression
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

<p class="fragment"><code>constexpr</code> function can be evaluated in both compile time and runtime. Evaluation at compile time can occur when the result is assigned to <code>constexpr</code> variable and arguments can be evaluated at compile time.</p>

___

<h2><code>constexpr</code> functions restrictions</h2>
<p>In C++11 <code>constexpr</code> functions were very restricted - only 1 return instruction (not returning void). From C++14 the only restrictions are, that function must not:</p>
<ul>
    <li class="fragment">contain <code>static</code> or <code>thread_local</code> variables</li>
    <li class="fragment">contain uninitialized variables</li>
    <li class="fragment">call non <code>constexpr</code> function</li>
    <li class="fragment">use non-literal types</li>
    <li class="fragment">be virtual (until C++20)</li>
    <li class="fragment">use asm code blocks (until C++20)</li>
    <li class="fragment">have try-catch block or throw exceptions (until C++20)</li>
</ul>

___

<h2><code>constexpr</code> constructor</h2>

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

<p>class <code>Point</code> can be used in constexpr computations, eg in constexpr functions. It is a literal type. Constexpr constructor has the same restrictions as a constexpr function and a class cannot have a virtual base class.</p>

___

<h2><code>constexpr</code> lambda</h2>
<p>From C++17 all lambda functions are by default implicitly marked as constexpr, if possible. <code>constexpr</code> keyword can also be used explicitly.</p>

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

<h2><code>constexpr if</code></h2>

```cpp
if constexpr (a < 0)
    doThis();
else if constexpr (a > 0)
    doThat();
else
    doSomethingElse();
```

<p><code>constexpr if</code> selects only one block of instructions, depending on which condition is met. The condition and other blocks are not compiled in the binary. The condition must be a constant expression.</p>

___

<h2><code>constexpr if</code> in SFINAE</h2>
<p><code>constexpr if</code> allows a simplification of template code used by SFINAE idiom.</p>

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
