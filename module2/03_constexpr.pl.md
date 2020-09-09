<!-- .slide: data-background="#111111" -->
# `constexpr`

___

## `constexpr` słowo kluczowe

<p> <strong> Uzasadnienie </strong>: szybsze binarne środowisko wykonawcze dzięki przeniesieniu niektórych obliczeń w czasie kompilacji. </p>
<p><code>constexpr</code> jest wyrażeniem, które można ocenić w czasie kompilacji i może pojawić się w <a href="https://en.cppreference.com/w/cpp/language/constant_expression">stałe wyrażenia</a>. Możemy mieć: </p>

* <!-- .element: class="fragment fade-in" --> zmienna constexpr
* <!-- .element: class="fragment fade-in" --> funkcja constexpr
* <!-- .element: class="fragment fade-in" --> Konstruktor constexpr
* <!-- .element: class="fragment fade-in" --> constexpr lambda (domyślnie z C ++ 17)
* <!-- .element: class="fragment fade-in" --> constexpr if (do C ++ 17)

___

## `constexpr` zmienne

```cpp
int a = 10;             // variable
const int b = 20;       // constant
const double c = 20;    // constant
constexpr int d = 30;   // constant at compile-time

constexpr auto e = a;   // error: initializer is not a contant expression
constexpr auto f = b;   // OK for integral, C++03 compatibility exception
constexpr auto g = c;   // error: initializer is not a contant expression
constexpr auto h = d;   // OK
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>constexpr</code> zmienną należy natychmiast zainicjować stałym wyrażeniem. <code>const</code> nie trzeba inicjować wyrażeniem stałym.
* <!-- .element: class="fragment fade-in" --> <code>constexpr</code> zmienna musi być <a href="https://en.cppreference.com/w/cpp/named_req/LiteralType">LiteralType</a>

___

## `constexpr` Funkcje

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

<p class = "fragment"><code>constexpr</code> funkcja może być oceniana zarówno w czasie kompilacji, jak iw czasie wykonywania. Ocena w czasie kompilacji może wystąpić, gdy wynik jest przypisany do <code>constexpr</code> zmienna i argumenty mogą być oceniane w czasie kompilacji. </p>

___

<h2><code>constexpr</code> ograniczenia funkcji </h2>
<p> W C ++ 11 <code>constexpr</code> funkcje były bardzo ograniczone - tylko 1 instrukcja powrotu (nie zwracająca void). Od C ++ 14 jedynymi ograniczeniami jest ta funkcja nie może: </p>
<ul>
    <li class = "fragment"> zawierają <code>static</code> lub <code>thread_local</code> zmienne </li>
    <li class = "fragment"> zawierają niezainicjowane zmienne </li>
    <li class = "fragment"> call non <code>constexpr</code> funkcja </li>
    <li class = "fragment"> użyj typów nieliteralnych </li>
    <li class = "fragment"> bądź wirtualny (do C ++ 20) </li>
    <li class = "fragment"> użyj bloków kodu asm (do C ++ 20) </li>
    <li class = "fragment"> mają blokowanie try-catch lub wyjątki rzutów (do C ++ 20) </li>
</ul>

___

<h2><code>constexpr</code> konstruktor </h2>

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

<p> klasa <code>Point</code> może być używany w obliczeniach constexpr, np. w funkcjach constexpr. To jest typ dosłowny. Konstruktor Constexpr ma takie same ograniczenia jak funkcja constexpr i klasa nie może mieć wirtualnej klasy bazowej. </p>

___

<h2><code>constexpr</code> lambda </h2>
<p> Od C ++ 17 wszystkie funkcje lambda są domyślnie oznaczane niejawnie jako constexpr, jeśli to możliwe. <code>constexpr</code> słowo kluczowe może być również użyte jawnie. </p>

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

<h2><code>constexpr if</code></h2>

```cpp
if constexpr (a < 0)
    doThis();
else if constexpr (a > 0)
    doThat();
else
    doSomethingElse();
```

<p><code>constexpr if</code> wybiera tylko jeden blok instrukcji, w zależności od tego, który warunek jest spełniony. Warunek i inne bloki nie są kompilowane w postaci binarnej. Warunek musi być wyrażeniem stałym. </p>

___

<h2><code>constexpr if</code> w SFINAE </h2>
<p><code>constexpr if</code> pozwala na uproszczenie kodu szablonu używanego przez idiom SFINAE. </p>

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

## Ćwiczenie

Napisz funkcję obliczającą n-tą liczbę Fibonacciego. Nie zaznaczaj tego `constexpr`.

W pierwszej linii `main()` dodaj obliczenie 45-tej liczby Fibonacciego. Zmierz czas wykonania programu (`time ./modern_cpp`)

Zaznacz funkcję Fibonacciego jako `constexpr`, skompiluj program i jeszcze raz zmierz czas wykonania.

Jeśli nie widzisz dużej różnicy, przypisz wynik do zmiennej constexpr.
