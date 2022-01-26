<!-- .slide: data-background="#111111" -->
# `constexpr`

___

## Słowo kluczowe `constexpr`

**Motywacja**: Szybsze programy, dzięki wykonaniu niektórych obliczeń podczas kompilacji.

`constexpr` jest wyrażeniem, które może w czasie kompilacji wykonać obliczenia i wstawić już gotowy wynik do binarki zamiast uruchamiać algorytm podczas wykonania programu. Możemy mieć:

* <!-- .element: class="fragment fade-in" --> zmienne constexpr
* <!-- .element: class="fragment fade-in" --> funkcje constexpr
  * <!-- .element: class="fragment fade-in" --> zwykłe funkcje constexpr
  * <!-- .element: class="fragment fade-in" --> konstruktor constexpr
  * <!-- .element: class="fragment fade-in" --> lambdę constexpr (domyślnie od C++17)
  * <!-- .element: class="fragment fade-in" --> destruktor constexpr (od C++20)
* <!-- .element: class="fragment fade-in" --> constexpr if (od C++17)

___

## zmienne `constexpr`

```cpp
int a = 10;             // variable
const int b = 20;       // constant
const double c = 20;    // constant
constexpr int d = 30;   // constant at compile-time

constexpr auto e = a;   // error: initializer is not a constant expression
constexpr auto f = b;   // OK for integral, C++03 compatibility exception
constexpr auto g = c;   // error: initializer is not a constant expression
constexpr auto h = d;   // OK
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Zmienną <code>constexpr</code> należy natychmiast zainicjować wyrażeniem stałym. <code>const</code> nie trzeba inicjować wyrażeniem stałym.
* <!-- .element: class="fragment fade-in" --> Zmienna <code>constexpr</code> może być typem wbudowanym (konkretniej <a href="https://en.cppreference.com/w/cpp/named_req/LiteralType">LiteralType</a>) lub dowolnym typem, który posiada konstruktor <code>constexpr</code>.

___

## Funkcje `constexpr`

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

Funkcja `constexpr` może zostać wykonana zarówno w czasie kompilacji, jak i w czasie działania programu. Wykonanie w czasie kompilacji na pewno nastąpi, gdy wynik przypisujemy do zmiennej `constexpr`. Argumenty funkcji muszą być znane na etapie kompilacji.
<!-- .element: class="fragment fade-in" -->

___

## Ograniczenia funkcji `constexpr`

W C++11 `constexpr` funkcje były bardzo ograniczone - tylko 1 instrukcja powrotu (nie zwracająca void). Od C++17 jedyne ograniczenia są takie, że funkcja:

* <!-- .element: class="fragment fade-in" --> nie może zawierać zmiennych <code>static</code> lub <code>thread_local</code>
* <!-- .element: class="fragment fade-in" --> nie może zawierać niezainicjowanych zmiennych
* <!-- .element: class="fragment fade-in" --> nie może wywołać funkcji nie-<code>constexpr</code>
* <!-- .element: class="fragment fade-in" --> nie może być wirtualna (do C++20)
* <!-- .element: class="fragment fade-in" --> nie może zawierać bloków try-catch (do C++20)
* <!-- .element: class="fragment fade-in" --> nie może być korutyną (od C++20)

Dokładniejsza rozpiska na [cppreference.com](https://en.cppreference.com/w/cpp/language/constexpr).
<!-- .element: class="fragment fade-in" -->

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

Klasa `Point` może być używana w obliczeniach `constexpr`, np. w funkcjach `constexpr`.

Konstruktor `constexpr` ma takie same ograniczenia jak funkcja `constexpr`. Dodatkowo klasa z konstruktorem `constexpr` nie może mieć wirtualnej klasy bazowej.

___

## `constexpr` lambda

Od C++17 wszystkie funkcje lambda są domyślnie oznaczane jako `constexpr` (niejawnie), jeśli to możliwe. Słowo kluczowe `constexpr` może być również użyte jawnie.

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

## `constexpr if`

```cpp
if constexpr (a < 0) {
    doThis();
} else if constexpr (a > 0) {
    doThat();
} else {
    doSomethingElse();
}
```

`constexpr if` wybiera tylko jeden blok instrukcji, w zależności od tego, który warunek jest spełniony. Warunek i inne bloki nie są wkompilowane w binarkę, będzie w niej tylko jeden blok kodu, w zależności od warunku. Warunek musi być wyrażeniem stałym.</p>

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

Oznacz funkcję jako `constexpr`, skompiluj program i jeszcze raz zmierz czas wykonania.

Jeśli nie widzisz dużej różnicy, przypisz wynik do zmiennej `constexpr`.
