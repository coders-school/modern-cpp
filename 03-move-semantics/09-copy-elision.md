## Copy elision

Unikanie zbędnych kopii

* <!-- .element: class="fragment fade-in" --> omijamy konstruktory kopiujące i przenoszące
* <!-- .element: class="fragment fade-in" --> otrzymujemy brak kopii przy przekazywaniu przez wartość

___

## Obowiązkowe copy elision od C++17

### RVO (Return Value Optimization)

```cpp
T f() {
    return T();
}
f();             // only one call to default c-tor of T
T x = T{T{f()}}; // only one call to default c-tor of T, to initialize x
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> w klauzuli <code>return</code>, kiedy obiekt jest tymczasowy (RVO - Return Value Optimization)
* <!-- .element: class="fragment fade-in" --> podczas inicjalizacji, kiedy inicjalizujemy tymczasowym obiektem tego samego typu

Nie próbuj optymalizować kodu dopisując `return std::move(sth);`. To może zapobiec optymalizacjom.
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
* <!-- .element: class="fragment fade-in" --> RVO jest obowiązkowe od C++17, NRVO nie
* <!-- .element: class="fragment fade-in" --> ale niektóre kompilatory i tak przeprowadzają NRVO 🙂

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
