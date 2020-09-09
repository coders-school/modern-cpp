<!-- .slide: data-background="#111111" -->
# `noexcept`

___

## `noexcept` słowo kluczowe

**Racjonalne uzasadnienie**: gwarancja bezpieczeństwa wyjątków bez rzucania, mniej kodu generowanego do obsługi wyjątków, dodatkowa optymalizacja kompilatora </p>

Określa, czy funkcja będzie zgłaszać wyjątki, czy nie. Jeśli wyjątek zostanie wyrzucony z `noexcept` funkcjonować, `std::terminate` jest nazywany.
<!-- .element: class="fragment fade-in" -->

```c++
void bar() noexcept(true) {}
void baz() noexcept { throw 42; }
// noexcept is the same as noexcept(true)

int main() {
    bar(); // fine
    baz(); // compiles, but calls std::terminate
}
```
<!-- .element: class="fragment fade-in" -->

___

## `noexcept` operator

Plik `noexcept` Operator wykonuje kontrolę w czasie kompilacji, która zwraca wartość true, jeśli wyrażenie zostało zadeklarowane, aby nie zgłaszać żadnych wyjątków. Zwraca wartość bool.

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

## `noexcept` słowo kluczowe

Ponieważ specyfikacja wyjątków C ++ 17 jest częścią systemu typów. Poniższe funkcje są funkcjami dwóch różnych typów:

- `void f() noexcept(true);`
- `void f() noexcept(false);`

Ta zmiana wzmacnia system typów, np. zezwalając interfejsom API na wymaganie niewyrzucających wywołań zwrotnych.

___

## Ćwiczenie

znak `getArea()` i `getPerimeter()` metody w `Rectangle` tak jak `noexcept`.
