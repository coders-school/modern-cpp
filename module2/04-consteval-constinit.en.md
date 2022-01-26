<!-- .slide: data-background="#111111" -->
# `consteval`, `constinit`

___

## Słowo kluczowe `consteval`

Od C++20 możemy używać `consteval` dla funkcji (tylko).

Oznacza to gwarancję wykonania na etapie kompilacji. `constexpr` mogło się wykonać także w czasie działania programu.

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

## Słowo kluczowe `constinit`

Od C++20 można używać `constinit` dla zmiennych statycznych lub `thread_local` (tylko).

Oznacza to gwarancję, że zmienna na pewno będzie statycznie zainicjalizowana, czyli będzie zainicjalizowana zerami lub wartością stałą znaną na etapie kompilacji. Wyklucza to posiadanie niezainicjalizowanej zmiennej.

Wprowadzone tylko po to, aby uniknąć problemu zwanego Static Initialization Order Fiasco.

```cpp
const char *g() { return "dynamic initialization"; }
constexpr const char *f(bool p) { return p ? "constant initializer" : g(); }

constinit const char *c = f(true); // OK
// constinit const char *d = f(false); // error

```
<!-- .element: class="fragment fade-in" -->
