<!-- .slide: data-background="#111111" -->
## Wyrównanie struktur danych (`alignas`, `alignof`)

___

### Słowo kluczowe _`alignas`_

`alignas` można zastosować do:

- deklaracji zmiennej lub składnika klasy
- deklaracji lub definicji klasy/struktury/unii lub wyliczenia

`alignas(expression)` - "expression" musi być potęgą 2.

`alignas(type-id)` - równoważny `alignas(alignof(type-id))`

`alignas(0)` - nie ma żadnego efektu

**Wyjątek:** Jeśli `alignas` osłabiłoby wyrównanie, które miałby typ bez `alignas`, nie zostanie ono zastosowane.

___

### Słowo kluczowe _`alignas`_

```c++
// every object of type see_t will be aligned to 16-byte boundary
struct alignas(16) see_t {
    float see_data[4];
};

// error: requested alignment is not a positive power of 2 alignas(129) char cacheline[128];
alignas(129) char cacheline[128];
```

___

##### Słowo kluczowe _`alignof`_

`alignof` zwraca wartość typu `std::size_t`, czyli wyrównanie w bajtach. Jeśli typ jest typem referencyjnym, operator zwraca wyrównanie typu, do którego się odwołuje; jeśli typ jest typem tablicowym, zwracane jest wymaganie wyrównania typu elementu.

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

## Zadanie

Zmień wyrównanie klasy `Circle` do 128.

Wypisz wyrównanie w funkcji `main()`.

Zmień wyrównanie na 2.

Wypisz wyrównanie.
