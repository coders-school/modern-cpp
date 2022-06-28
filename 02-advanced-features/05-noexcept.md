<!-- .slide: data-background="#111111" -->
# `noexcept`

___

## `noexcept` keyword

**Rationale**: no-throw exception safety guarantee, less code generated for exceptions handling, additional compiler optimisation.

Specifies whether a function will throw exceptions or not. If an exception is thrown out of a `noexcept` function, `std::terminate` is called.
<!-- .element: class="fragment fade-in" -->

```c++
void foo() noexcept {}
void bar() noexcept { throw 42; }
// noexcept is the same as noexcept(true)

int main() {
    foo(); // fine
    bar(); // compiles, but calls std::terminate
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

## `noexcept` specifier

Since C++17 exceptions specification is a part of the type system. Below functions are functions of two distinct types:

* `void f() noexcept {}`
* `void f() {}`

This change strengthens the type system, e.g. by allowing APIs to require non-throwing callbacks.

___

## `throw` specifier

`throw` specifier used after a function declaration was removed in C++17. It was marked as deprecated in C++11.

```cpp
void f() throw(std::runtime_error);    // f can throw std::runtime_error
void g() throw(std::runtime_error, std::logic_error);
```

Keeping the list of possible exceptions consistent with the implementation was usually impossible.

___

## Remarks

* <!-- .element: class="fragment fade-in" --> Marking function as <code>noexcept</code> does not mean that you can't handle exceptions inside.
* <!-- .element: class="fragment fade-in" --> <code>noexcept</code> means, that from this function no exception can be thrown (either directly by <code>throw</code> or indirectly when the exception is propagated).
* <!-- .element: class="fragment fade-in" --> Inside <code>noexcept</code> functions you can freely use <code>try-catch</code> blocks to handle exceptions and not let them propagate outside.
* <!-- .element: class="fragment fade-in" --> Thanks to <code>noexcept</code> we can know what kind of exception occurred, because the binary will be terminated. We can handle this situation more properly rather than just ignoring the exception.

___

## Exercise

Mark `getArea()` and `getPerimeter()` methods in `Rectangle` as `noexcept`.
