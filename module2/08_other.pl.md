<!-- .slide: data-background="#111111" -->
# Inne przydatne funkcje

___

## Zagnieżdżone definicje przestrzeni nazw (C++17)

Możesz zagnieżdżać przestrzenie nazw w następujący sposób:

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

## Dedukcja argumentów szablonu klasy (C++17)

Z szablonu klasy C++17 można wywnioskować argumenty automatycznie. Automatyczna dedukcja argumentów szablonów była dostępna wcześniej tylko dla funkcji szablonów.

```c++
std::pair p(1, 'x'); // C++17: OK, C++14: error: missing
                     //template arguments before p
std::pair<int, std::string> p(1, 'x'); // C++14: OK
auto p = std::make_pair(1, 'x'); // C++17: OK, C++14: OK
```

___

## Instrukcje wyboru z inicjatorem (C++17)

Nowe wersje `if` i `switch` dla C++:

___

## `if (init; condition)`

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

```cpp
status_code foo() { // C++17
    if (status_code c = bar(); c != SUCCESS) {
        return c;
    }
    // ...
}
```

___

## `switch (init; condition)`

```c++
{
    Foo gadget(args);
    switch (auto s = gadget.status()) { // C++14
        case OK: gadget.zip(); break;
        case Bad: throw BadFoo(s.message());
    }
}
```

```c++
switch (Foo gadget(args); auto s = gadget.status()) { // C++17
    case OK: gadget.zip(); break;
    case Bad: throw BadFoo(s.message());
}
```

___

## Przegląd

[Przegląd nowoczesnych funkcji C++](https://github.com/AnthonyCalandra/modern-cpp-features#stdfilesystem)
