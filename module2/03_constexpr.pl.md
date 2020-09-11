<!-- .slide: data-background="#111111" -->
# `constexpr`

___

## Słowo kluczowe `constexpr`

Szybsze binarne środowisko wykonawcze dzięki przeniesieniu niektórych obliczeń w czasie kompilacji.

`constexpr` jest wyrażeniem, które można ocenić w czasie kompilacji i może pojawić się jako wyrażenie stałe ([constant expression](https://en.cppreference.com/w/cpp/language/constant_expression)). Możemy mieć:

* <!-- .element: class="fragment fade-in" --> zmienną constexpr
* <!-- .element: class="fragment fade-in" --> funkcję constexpr
* <!-- .element: class="fragment fade-in" --> konstruktor constexpr
* <!-- .element: class="fragment fade-in" --> lambdę constexpr (domyślnie z C++17)
* <!-- .element: class="fragment fade-in" --> constexpr if (do C++17)

___

## zmienne `constexpr`

```cpp
int a = 10;             // zmienna
const int b = 20;       // stała
const double c = 20;    // stała
constexpr int d = 30;   // stała podczas procesu kompilacji

constexpr auto e = a;   // error: inicjator nie jest wyrażeniem stałym
constexpr auto f = b;   // OK dla typu int, wyjątek dla wstecznej kompatybilności z C++03
constexpr auto g = c;   // error: inicjator nie jest wyrażeniem stałym
constexpr auto h = d;   // OK
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Zmienną <code>constexpr</code> należy natychmiast zainicjować stałym wyrażeniem. <code>const</code> nie trzeba inicjować wyrażeniem stałym.
* <!-- .element: class="fragment fade-in" --> Zmienna <code>constexpr</code> musi być typu <a href="https://en.cppreference.com/w/cpp/named_req/LiteralType">LiteralType</a>

___

## Funkcje `constexpr`

```cpp
constexpr int factorial11(int n) {  // kompatybilne z C++11
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

Funkcja `constexpr` może być oceniana zarówno w czasie kompilacji, jak i w czasie wykonywania. Ocena w czasie kompilacji może wystąpić, gdy wynik jest przypisany do zmiennej `constexpr` i argumenty mogą być oceniane w czasie kompilacji.
<!-- .element: class="fragment fade-in" -->

___

## Ograniczenia funkcji `constexpr`

W C++11 `constexpr` funkcje były bardzo ograniczone - tylko 1 instrukcja powrotu (nie zwracająca void). Od C++14 jedyne ograniczenia mówią, że funkcja nie może:

* <!-- .element: class="fragment fade-in" --> zawierać zmiennych <code>static</code> lub <code>thread_local</code>
* <!-- .element: class="fragment fade-in" --> zawierać niezainicjowanych zmiennych
* <!-- .element: class="fragment fade-in" --> wywołać funkcji bez <code>constexpr</code>
* <!-- .element: class="fragment fade-in" --> używać typów nieliteralnych
* <!-- .element: class="fragment fade-in" --> być wirtualna (do C++20)
* <!-- .element: class="fragment fade-in" --> używać bloków kodu asm (do C++20)
* <!-- .element: class="fragment fade-in" --> zawierać bloków try-catch lub rzucać wyjątkami (do C++20)

___

## `constexpr` konstruktor

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

Klasa `Point` może być używana w obliczeniach `constexpr`, np. w funkcjach `constexpr`. Jest to typ literalny. Konstruktor `constexpr` ma takie same ograniczenia jak funkcja `constexpr` i klasa nie może mieć wirtualnej klasy bazowej.

___

## `constexpr` lambda

Od C++17 wszystkie funkcje lambda są domyślnie oznaczane niejawnie jako `constexpr`, jeśli to możliwe. Słowo kluczowe `constexpr` może być również użyte jawnie.

```cpp
auto squared = [](auto x) {             // niejawny constexpr
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

`constexpr if` wybiera tylko jeden blok instrukcji, w zależności od tego, który warunek jest spełniony. Warunek i inne bloki nie są kompilowane w postaci binarnej. Warunek musi być wyrażeniem stałym. </p>

___

## `constexpr if` w idiomie SFINAE

`constexpr if` pozwala na uproszczenie kodu szablonu używanego przez idiom SFINAE.

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

## Zadanie

Napisz funkcję obliczającą n-tą liczbę Fibonacciego. Nie zaznaczaj jej jako `constexpr`.

W pierwszej linii `main()` dodaj obliczenie 45-tej liczby Fibonacciego. Zmierz czas wykonania programu (`time ./modern_cpp`)

Zaznacz funkcję Fibonacciego jako `constexpr`, skompiluj program i jeszcze raz zmierz czas wykonania.

Jeśli nie widzisz dużej różnicy, przypisz wynik do zmiennej `constexpr`.
