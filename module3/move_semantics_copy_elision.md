## Copy elision

* <!-- .element: class="fragment fade-in" --> omits copy and move constructors
* <!-- .element: class="fragment fade-in" --> results in zero-copy pass-by-value semantics

___

## Mandatory copy elision from C++17

```cpp
T f() {
    return T();
}
f();             // only one call to default c-tor of T
T x = T(T(f())); // only one call to default c-tor of T, to initialize x
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> in return statement, when the object is temporary (RVO - Return Value Optimisation)
* <!-- .element: class="fragment fade-in" --> in the initialization, when the initializer is of the same class and is temporary

Do not try to "optimize" code by writing `return std::move(sth);`. It may prevent optimizations.
<!-- .element: class="fragment fade-in" -->

[Copy elision on cppreference.com](https://en.cppreference.com/w/cpp/language/copy_elision)
<!-- .element: class="fragment fade-in" -->

___

## RVO and NRVO

```cpp
T f() {
    T t;
    return t;  // NRVO
}
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> NRVO = Named RVO
* <!-- .element: class="fragment fade-in" --> RVO is mandatory from C++17, NRVO not

```cpp
T bar()
{
    T t1{1};
    T t2{2};
    return (std::time(nullptr) % 2) ? t1 : t2;
}  // don't know which object will be elided
```
<!-- .element: class="fragment fade-in" -->

[RVO and NRVO on cpp-polska.pl](https://cpp-polska.pl/post/zarzadzanie-zasobami-w-c-3-rvo-nrvo-i-obowiazkowe-rvo-w-c17)
<!-- .element: class="fragment fade-in" -->
