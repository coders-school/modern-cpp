<!-- .slide: data-background="#111111" -->
# Wyrównanie struktur danych

## `alignas`, `alignof`

___

## Słowo kluczowe `alignas`

```c++
alignas(int) char variable;

// every object of type see_t will be aligned to 16-byte boundary
struct alignas(16) see_t {
    float see_data[4];
};

// error: requested alignment is not a positive power of 2
alignas(129) char cacheline[128];
```

___

## Słowo kluczowe `alignas`

`alignas` można zastosować do:

- deklaracji zmiennej lub składnika klasy
- deklaracji lub definicji klasy/struktury/unii/enuma

`alignas(expression)` - "expression" musi być potęgą 2.
<!-- .element: class="fragment fade-in" -->

`alignas(type-id)` - równoważny `alignas(alignof(type-id))`
<!-- .element: class="fragment fade-in" -->

`alignas(0)` - nie ma żadnego efektu
<!-- .element: class="fragment fade-in" -->

Jeśli `alignas` zmniejszyłoby wyrównanie, które miałby typ bez `alignas`, to nie zostanie ono zastosowane.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.8em" -->
## Słowo kluczowe `alignof`

`alignof` zwraca wartość typu `std::size_t`, czyli wyrównanie w bajtach.
<!-- .element: class="fragment fade-in" -->

<div style="display: flex;">

<div style="width: 420px" class="fragment fade-in">

```c++
#include <iostream>
using namespace std;

struct Foo {
    int i;
    float f;
    char c;
};
struct Empty{};
struct alignas(64) Empty64 {};
struct alignas(1) Double {
    double d;
};
```

</div>

<div style="width: 750px" class="fragment fade-in">

```c++


int main() {
  cout << "Alignment of" << '\n'
       << "char: "      << alignof(char)    << '\n' // 1
       << "pointer: "   << alignof(int*)    << '\n' // 8
       << "class Foo: " << alignof(Foo)     << '\n' // 4
       << "Empty: "     << alignof(Empty)   << '\n' // 1
       << "Empty64: "   << alignof(Empty64) << '\n' // 64
       << "Double: "    << alignof(Double)  << '\n' // 8
}



```

</div>

</div>

Jeśli typ jest typem referencyjnym, operator zwraca wyrównanie typu, do którego się odwołuje;
<!-- .element: class="fragment fade-in" -->

Jeśli typ jest typem tablicowym, zwracane jest wyrównanie pojedynczego elementu.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Zmień wyrównanie klasy `Circle` na 128.

Wypisz to wyrównanie w funkcji `main()`.

Zmień wyrównanie na 2.

Wypisz to wyrównanie i zobacz co się stanie.
