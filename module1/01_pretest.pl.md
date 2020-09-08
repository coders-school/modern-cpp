<!-- .slide: data-background="#111111" -->

# Test wstępny

___

## 1. Jaki jest typ zmiennej `v`?

```cpp
int i = 42;
const auto v = &i;
```

1. `const int`
1. `const int&`
1. `const int*`
1. inne

___

## 2. Które z poniższych inicjalizacji są poprawne w C++14?

```cpp
struct P { int a, b };
```

1. `int values[] = { 1, 2, 3, 4, 5 };`
1. `P v = { 1, 4 };`
1. `P v{1, 4};`
1. `P v(1, 4);`
1. `std::vector<int> v = { 1, 2, 3, 4 };`
1. `std::vector<int> v(1, 2, 3, 4);`
1. `int v[] = { 1, 3, 5, 6.6 };`

___

## 3. Które z poniższych elementów można zdefiniować jako usunięte (`= delete;`)?

1. domyślny konstruktor
1. konstruktor kopiujący
1. konstruktor ruchu
1. operator przypisania kopii
1. operator przypisania ruchu
1. destructor
1. darmowa funkcja
1. metoda klasowa
1. obiekt członka klasy
