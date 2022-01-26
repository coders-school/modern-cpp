<!-- .slide: data-background="#111111" -->
# Inne przydatne nowości

___

## Zagnieżdżone definicje przestrzeni nazw

Od C++17 można zagnieżdżać przestrzenie nazw w następujący sposób:

```c++
namespace A::B::C {
  ...
}
```

Zamiast tego:

```c++
namespace A {
  namespace B {
    namespace C {
      ...
    }
  }
}
```

___

## Dedukcja typów szablonu klasy (C++17)

Od C++17 typy szablonów klas mogą być wydedukowane automatycznie na podstawie argumentów przekazanych do konstruktora. Do C++17 automatyczna dedukcja typów szablonów była dostępna tylko dla szablonów funkcji.

```c++
std::pair p{1, 'x'}; // C++17: OK, C++14: error: missing
                     //template arguments before p
std::pair<int, std::string> p(1, 'x'); // C++14: OK
auto p = std::make_pair(1, 'x'); // C++17: OK, C++14: OK

std::vector v = {1, 2, 3, 4}; // C++17: OK, std::vector<int>
```

___

## Instrukcje warunkowe z inicjatorem

Od C++17 są nowe wersje instrukcji `if` i `switch`.

___

## `if (init; condition)`

```cpp
status_code foo() { // C++17
    if (status_code c = bar(); c != SUCCESS) {
        return c;
    }
    // ...
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
status_code foo() { // C++14
    { //variable c scope
        status_code c = bar();
        if (c != SUCCESS) {
            return c;
        }
    }
    // ...
}
```
<!-- .element: class="fragment fade-in" -->

___

## `switch (init; condition)`

```c++
switch (Foo gadget(args); auto s = gadget.status()) { // C++17
    case OK: gadget.zip(); break;
    case Bad: throw BadFoo(s.message());
}
```
<!-- .element: class="fragment fade-in" -->

```c++
{
    Foo gadget(args);
    switch (auto s = gadget.status()) { // C++14
        case OK: gadget.zip(); break;
        case Bad: throw BadFoo(s.message());
    }
}
```
<!-- .element: class="fragment fade-in" -->

___

## Przegląd

[Przegląd funkcjonalności nowoczesnego C++](https://github.com/AnthonyCalandra/modern-cpp-features)
