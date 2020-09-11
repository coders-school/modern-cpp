<!-- .slide: data-background="#111111" -->
# `noexcept`

___

## Słowo kluczowe `noexcept`

Gwarancja bezpieczeństwa nie wyrzucania wyjątków, mniej kodu generowanego do obsługi wyjątków, dodatkowa optymalizacja kompilatora.

Określa, czy funkcja będzie zgłaszać wyjątki, czy nie. Jeśli wyjątek zostanie wyrzucony z funkcji `noexcept`, zostanie wywołany `std::terminate`.
<!-- .element: class="fragment fade-in" -->

```c++
void bar() noexcept(true) {}
void baz() noexcept { throw 42; }
// noexcept - to samo co noexcept(true)

int main() {
    bar(); // ok
    baz(); // kompiluje się, ale wywołuje std::terminate
}
```
<!-- .element: class="fragment fade-in" -->

___

## Operator `noexcept`

Operator `noexcept` wykonuje kontrolę w czasie kompilacji, która zwraca wartość true, jeśli wyrażenie zostało zadeklarowane, aby nie zgłaszać żadnych wyjątków. Zwraca wartość bool.

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

## Słowo kluczowe `noexcept`

Ponieważ specyfikacja wyjątków C++17 jest częścią systemu typów, poniższe funkcje są funkcjami dwóch różnych typów:

- `void f() noexcept(true);`
- `void f() noexcept(false);`

Ta zmiana wzmacnia system typów, np. zezwalając interfejsom API na wymaganie funkcji niewyrzucających wyjątków.

___

## Zadanie

Oznacz metody `getArea()` i `getPerimeter()` w klasie `Rectangle` jako `noexcept`.
