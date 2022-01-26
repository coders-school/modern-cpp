<!-- .slide: data-background="#111111" -->
# `noexcept`

___

## Słowo kluczowe `noexcept`

**Motywacja**: gwarancja nie wyrzucania wyjątków, mniej kodu generowanego do obsługi wyjątków, dodatkowe optymalizacje kompilatora.

`noexcept` określa, czy funkcja będzie rzucać lub propagować wyjątki, czy nie. Jeśli wyjątek zostanie wyrzucony z funkcji `noexcept`, zostanie wywołane `std::terminate`.
<!-- .element: class="fragment fade-in" -->

```c++
void foo() noexcept {}
void bar() noexcept { throw 42; }
// noexcept is the same as noexcept(true)

int main() {
    foo(); // fine
    bar(); // compiles, but calls std::terminate
}
```
<!-- .element: class="fragment fade-in" -->

___

## Operator `noexcept`

Operator `noexcept` sprawdza w czasie kompilacji, czy dane wyrażenie jest zadeklarowane jako `noexcept`. Zwraca wartość bool.

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

## Przeciążenia funkcji z `noexcept`

Specyfikator `noexcept` od C++17 jest częścią systemu typów, więc poniższe funkcje są traktowane jako dwie różne funkcje:

* `void f() noexcept {}`
* `void f() {}`

Dzięki tej zmianie możemy tworzyć interfejsy, które wymagają, aby określone funkcje nie rzucały wyjątków.

___

## Specyfikator `throw`

Specyfikator `throw` użyty za nazwą funkcji został usunięty w C++17, a od C++11 był oznaczony jako przestarzały (deprecated).

```cpp
void f() throw(std::runtime_error);    // f can throw std::runtime_error
void g() throw(std::runtime_error, std::logic_error);
```

Utrzymywanie listy możliwych wyjątków rzucanych przez funkcję było dodatkową pracą i często implementacja rozjeżdżała się z deklaracją.

___

## Uwagi

* <!-- .element: class="fragment fade-in" --> Oznaczenie funkcji jako <code>noexcept</code> nie oznacza, że nie można w niej obsługiwać wyjątków.
* <!-- .element: class="fragment fade-in" --> <code>noexcept</code> oznacza, że z funkcji nie może polecieć wyjątek (rzucony bezpośrednio za pomocą <code>throw</code> w ciele funkcji lub propagowany).
* <!-- .element: class="fragment fade-in" --> W funkcjach <code>noexcept</code> jak najbardziej można używać bloków <code>try-catch</code> aby wewnątrz obsłużyć wyjątki i nie pozwolić im się wydostać na zewnątrz.
* <!-- .element: class="fragment fade-in" --> Jednocześnie użycie <code>catch(...)</code> do złapania każdego wyjątku mija się z celem.
* <!-- .element: class="fragment fade-in" --> Dzięki <code>noexcept</code> dowiemy się, jaki wyjątek poleciał z funkcji, bo binarka zostanie ubita. Możemy przez to odpowiednio zareagować, a nie tylko zignorować wyjątek.

___

## Zadanie

Oznacz metody `getArea()` i `getPerimeter()` w klasie `Rectangle` jako `noexcept`.

Co się dzieje i jak to naprawić? :)
