<!-- .slide: data-background="#111111" -->
# `consteval`, `constinit`

___

## `consteval` keyword

From C++20 we can use `consteval` for functions (only).

`consteval` guarantees, that the function will be evaluated at the compile time. `constexpr` means that the function can also be executed at runtime.

```cpp
consteval int sqr(int n) {
  return n*n;
}
constexpr int r = sqr(100); // OK

int x = 100;
int r2 = sqr(x);            // Error: Call does not produce a constant
```
<!-- .element: class="fragment fade-in" -->

___

## `constinit` keyword

From C++20 we can use `constinit` for static or `thread_local` varaibles (only).

`constinit` guarantees that the variable will have static initialization, that is either zero initialization or constant initialization.

This eliminates the problem known as Static Initialization Order Fiasco.

```cpp
const char *g() { return "dynamic initialization"; }
constexpr const char *f(bool p) { return p ? "constant initializer" : g(); }

constinit const char *c = f(true); // OK
// constinit const char *d = f(false); // error

```
<!-- .element: class="fragment fade-in" -->
