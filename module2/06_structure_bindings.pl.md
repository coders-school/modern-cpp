<!-- .slide: data-background="#111111" -->
# Wiązanie struktur

___

## Wiązanie struktur

Przypisuje nowym nazwom obiekty lub elementy inicjalizatora:
<!-- Ciężko mi znaleźć odpowiednik do de-structuring -->

```cpp
auto [ x, y, z ] = expr;
```

 gdzie typ `expr` to obiekty podobne do krotek, których elementy byłyby powiązane ze zmiennymi `x`, `y` i `z` (które deklaruje ta konstrukcja).

 Typem `expr` mogą być: `std::tuple`, `std::pair`, `std::array` i agregaty.

___
<!-- .slide: style="font-size: 0.95em" -->

## Wiązanie struktur

```c++
using Coordinate = std::pair<int, int>;

Coordinate origin() {
    return Coordinate{0, 0};
}

const auto [ x, y ] = origin();
std::cout << "x: " << x << ", y: " << y;
```
<!-- .element: class="fragment fade-in" -->

```c++
std::unordered_map<std::string, int> mapping {
    {"a", 1},
    {"b", 2},
    {"c", 3}
};

for (const auto& [key, value] : mapping) {
    // Zrób coś z key i value
}
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Stworzyć `std::map<shared_ptr<Shape>, double>` który zapamięta kształt i jego obwód.

Użyj wiązań struktur, aby iterować po tej kolekcji i wyświetlić informacje o kształcie (wywołaj funkcję `print()`) oraz obwodzie.
