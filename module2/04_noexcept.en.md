<!-- .slide: data-background="#111111" -->
# `noexcept`

___

## `noexcept` keyword

**Rationale**: no-throw exception safety guarantee, less code generated for exceptions handling, additional compiler optimisation</p>

Specifies whether a function will throw exceptions or not. If an exception is thrown out of a `noexcept` function, `std::terminate` is called.
<!-- .element: class="fragment fade-in" -->

```c++
void bar() noexcept(true) {}
void baz() noexcept { throw 42; }
// noexcept is the same as noexcept(true)

int main() {
    bar(); // fine
    baz(); // compiles, but calls std::terminate
}
```
<!-- .element: class="fragment fade-in" -->

___

## `noexcept` operator

The `noexcept` operator performs a compile-time check that returns true if an expression is declared to not throw any exceptions. Returns bool.

```cpp
void may_throw();
void no_throw() noexcept;

int main() {
    std::cout << std::boolalpha
              << "Is may_throw() noexcept? "
              << noexcept(may_throw()) << '\n'        // false
              << "Is no_throw() noexcept? "
              << noexcept(no_throw()) << '\n';        // true
}
```

___

## `noexcept` keyword

Since C++17 exceptions specification is a part of the type system. Below functions are functions of two distinct types:

- `void f() noexcept(true);`
- `void f() noexcept(false);`

This change strengthens the type system, e.g. by allowing APIs to require non-throwing callbacks.

___

## Exercise

Mark `getArea()` and `getPerimeter()` methods in `Rectangle` as `noexcept`.
