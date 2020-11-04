<!-- .slide: data-background="#111111" -->
# Automatic type deduction

___

## `auto` keyword

```cpp
auto a;         // error: declaration of ‘auto a’ has no initializer
auto i = 42;    // i is int
auto u = 42u;   // u is unsigned
auto d = 42.0;  // d is double
auto f = 42.0f; // f is float

double f();
auto r1 = f();  // r1 is double

std::set<std::string> collection;
auto it = collection.begin(); // it is std::set<std::string>::iterator
```

**Rationale**: Not important (but strongly defined) types, less typing, less refactoring.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> A compiler can automatically deduce the type of variable during initialization
* <!-- .element: class="fragment fade-in" --> Deduction is made from a literal, other variable or a function return type
* <!-- .element: class="fragment fade-in" --> The same rules as for templates deduction are applied

___

## Variable modifiers

```cpp
int func() { return 10; }

int main() {
    const auto& v1 = func(); // v1 is const int&
    const auto v2 = func();  // v2 is const int
    // auto& v3 = func();    // error: cannot bind non-const lvalue reference
                             // of type ‘int&’ to an rvalue of type ‘int’
    auto v4 = func();        // v4 is int
    return 0;
}
```

___
<!-- .slide: style="font-size: 0.9em" -->

### Deduction rules for references

```cpp
const vector<int> values;
auto v1 = values;   // v1 : vector<int>
auto& v2 = values;  // v2 : const vector<int>&

volatile long clock = 0L;
auto c1 = clock;    // c1 : long
auto& c2 = clock;   // c2 : volatile long&

Gadget items[10];
auto g1 = items;    // g1 : Gadget*
auto& g2 = items;   // g2 : Gadget(&)[10] - a reference to
                    // the 10-elementh array of Gadgets

int func(double) { return 10; }
auto f1 = func;     // f1 : int (*)(double)
auto& f2 = func ;   // f2: int (&)(double)
```

* <!-- .element: class="fragment fade-in" --> Reference means the same object with the same properties
* <!-- .element: class="fragment fade-in" --> Reference preserves cv-qualifiers (<code>const</code>, <code>volatile</code>)
* <!-- .element: class="fragment fade-in" --> Copy drops cv-qualifiers
* <!-- .element: class="fragment fade-in" --> Copy of array decays to a pointer

___

### Function declaration with arrow

```cpp
int sum(int a, int b);
auto sum(int a, int b) -> int;


auto isEven = [](int a) -> bool {
    return a % 2;
}
```

Introduced to allow definition of the type returned from lambda functions.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

### Deduction of a function returned type

```cpp
auto multiply(int x, int y) {
    return x * y;
}

auto get_name(int id) {
    if (id == 1)
        return std::string("Gadget");
    else if (id == 2)
        return std::string("SuperGadget");
    return string("Unknown");
}

auto factorial(int n) {
    if (n == 1)
        return 1;
    return factorial(n - 1) * n;
}
```

* <!-- .element: class="fragment fade-in" --> Introduced in C++14
* <!-- .element: class="fragment fade-in" --> Deduction mechanism is the same as for deduction of variable types
* <!-- .element: class="fragment fade-in" --> All <code>return</code> instructions must return the same type
* <!-- .element: class="fragment fade-in" --> Recursion allowed only if recursive function call is not a first <code>return</code> statement

___

## range-based for loop

```cpp
std::vector<int> v = {0, 1, 2, 3, 4, 5};

for (const auto & element : v) {
    std::cout << element << ' ';
}
std::cout << '\n';
```

___

### Generated code for-range based for loop

```cpp
{
    auto && __range = range_expression ;
    auto __begin = begin_expr ;
    auto __end = end_expr ;
    for ( ; __begin != __end; ++__begin) {
        range_declaration = *__begin;
        loop_statement
    }
}
```

___
<!-- .slide: data-background="#cf802a" -->

## Exercise

Put auto wherever you think is good.

Use range-based for loops wherever possible.

### Let's have some fun :)
<!-- .element: class="fragment fade-in" -->

Connect to my VSC and edit my program simultaneously.
<!-- .element: class="fragment fade-in" -->
