<!-- .slide: data-background="#111111" -->
# Wyrównanie struktury danych (`alignas`, `alignof`)

___

### _`alignas`_ słowo kluczowe

Plik `alignas` specyfikator można zastosować do:

- deklaracja zmiennej lub element danych klasy
- deklaracja lub definicja klasy / struktury / unii lub wyliczenia

`alignas(expression)` - ekspresja musi mieć pozytywną moc 2.

`alignas(type-id)` - równoważny `alignas(alignof(type-id))`

`alignas(0)` - nie ma żadnego efektu

**Wyjątek:** Jeśli `alignas` osłabiłoby wyrównanie, które miałby typ bez tego `alignas`, nie zostanie zastosowana. <!-- bolded "exceptions" to make it stand out more -->

___

### _`alignas`_ słowo kluczowe

```c++
// every object of type see_t will be alignet to 16-byte boundary
struct alignas(16) see_t {
    float see_data[4];
};

// error: requested alignment is not a positive power of 2 alignas(129) char cacheline[128];
alignas(129) char cacheline[128];
```

___

##### _`alignof`_ słowo kluczowe

Plik `alignof` specyfikator zwraca wartość typu `std::size_t`, czyli wyrównanie w bajtach. Jeśli typ jest typem referencyjnym, operator zwraca wyrównanie typu, do którego się odwołuje; jeśli typ jest typem tablicowym, zwracane jest wymaganie wyrównania typu elementu.

<div style="display: flex;">

<div>

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

<div>

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

___

## Ćwiczenie

Zmień wyrównanie `Circle` klasa do 128.

Wydrukuj wyrównanie w formacie `main()` funkcjonować.

Zmień wyrównanie na 2.

Wydrukuj wyrównanie.
