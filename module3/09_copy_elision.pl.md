## Copy elision

* <!-- .element: class="fragment fade-in" --> pomija konstruktory kopiowania i przenoszenia
* <!-- .element: class="fragment fade-in" --> daje w wyniku semantykę przekazywania przez wartość bez kopiowania

___

## Copy elision obowiązkowe od C++17

```cpp
T f() {
    return T();
}
f();             // only one call to default c-tor of T
T x = T(T(f())); // only one call to default c-tor of T, to initialize x
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> w instrukcji return, gdy obiekt jest tymczasowy (RVO - Return Value Optimization)
* <!-- .element: class="fragment fade-in" --> podczas inicjalizacji, gdy inicjator jest tej samej klasy i jest tymczasowy

Nie próbuj „optymalizować” kodu pisząc `return std::move(sth);`. Może to uniemożliwić optymalizacje.
<!-- .element: class="fragment fade-in" -->

[Copy elision na cppreference.com](https://en.cppreference.com/w/cpp/language/copy_elision)
<!-- .element: class="fragment fade-in" -->

___

## RVO i NRVO

```cpp
T f() {
    T t;
    return t;  // NRVO
}
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> NRVO = Nazwane RVO
* <!-- .element: class="fragment fade-in" --> RVO jest obowiązkowe od C++17, NRVO nie

```cpp
T bar()
{
    T t1{1};
    T t2{2};
    return (std::time(nullptr) % 2) ? t1 : t2;
}  // don't know which object will be elided
```
<!-- .element: class="fragment fade-in" -->

[RVO i NRVO na cpp-polska.pl](https://cpp-polska.pl/post/zarzadzanie-zasobami-w-c-3-rvo-nrvo-i-obowiazkowe-rvo-w-c17)
<!-- .element: class="fragment fade-in" -->
