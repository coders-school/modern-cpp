<!-- .slide: data-background="#111111" -->
# alias typu `using`

___

## Aliasy typów

```cpp
typedef std::ios_base::fmtflags Flags;
using Flags = std::ios_base::fmtflags;  // the same as above
Flags fl = std::ios_base::dec;
```
<!-- .element: class="fragment fade-in" -->

```cpp
typedef std::vector<std::shared_ptr<Socket>> SocketContainer;
std::vector<std::shared_ptr<Socket>> typedef SocketContainer; // correct ;)
using SocketContainer = std::vector<std::shared_ptr<Socket>>;
```
<!-- .element: class="fragment fade-in" -->

**Motywacja**: Bardziej intuicyjne tworzenie aliasów.
<!-- .element: class="fragment fade-in" -->

Alias to nazwa odnosząca się do wcześniej zdefiniowanego typu. Można go utworzyć za pomocą `typedef`.
Od C++11 należy tworzyć aliasy typu za pomocą słowa kluczowego `using`.
<!-- .element: class="fragment fade-in" -->

___

### Aliasy szablonów

```cpp
template <typename T>
using StrKeyMap = std::map<std::string, T>;

StrKeyMap<int> my_map; // std::map<std::string, int>
```

Alias ​​typu można sparametryzować za pomocą szablonów. Z `typedef` było to niemożliwe.
<!-- .element: class="fragment fade-in" -->

Nie można tworzyć specjalizacji szablonowych aliasów.
<!-- .element: class="fragment fade-in" -->

___

### Dziedziczenie konstruktorów

```cpp
struct A {
    explicit A(int);
    int a;
};

struct B : A {
    using A::A;  // implicit declaration of B::B(int)
    B(int, int); // overloaded inherited Base ctor
};
```

Dzięki `using` możemy też "odziedziczyć" konstruktory, które normalnie nie są dziedziczone.

* <!-- .element: class="fragment fade-in" --> Konstruktory klas pochodnych są generowane niejawnie i tylko jeśli są używane
* <!-- .element: class="fragment fade-in" --> Konstruktory klas pochodnych przyjmują te same argumenty, co konstruktory klas bazowych
* <!-- .element: class="fragment fade-in" --> Konstruktor klasy pochodnej wywołuje odpowiedni konstruktor klasy bazowej
* <!-- .element: class="fragment fade-in" --> Dziedziczenie konstruktora w klasie, która posiada nowe pola, może być ryzykowne - nowe pola mogą być niezainicjowane

___

## Zadanie

Zamień `typedef` na `using`.
