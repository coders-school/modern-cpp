<!-- .slide: data-background="#111111" -->
# Structured bindings

___

## Structured bindings

Inicjalizacja kilku elementów jednocześnie, poprzez rozłożenie struktur lub tablic na ich składowe.

```cpp
auto [ x, y, z ] = expr;
```

Typem `expr` mogą być: `std::tuple`, `std::pair`, `std::array` i struktury agregujące.

___
<!-- .slide: style="font-size: 0.95em" -->

## Structured bindings

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

// De-structure by reference.
for (const auto& [key, value] : mapping) {
    std::cout << key << " | " << value << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Stwórz `std::map<shared_ptr<Shape>, double>` który zapamięta kształt i jego obwód.

Użyj structured bindings, aby przeiterować po tej kolekcji i wyświetlić informacje o kształcie (wywołaj metodę `print()`) oraz obwodzie.
