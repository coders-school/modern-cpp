<!-- .slide: data-background="#111111" -->
# Strukturalne powiązania
<!-- I haven't found enything in presentation you've send me with e-mail, so I've searched in repo from C++ course I was participating in, and put those informations here. If I missed something in your's presentatnion in PDF than, please, tell me witch slides to put here or if I should leave it blank. -->
___
## Strukturalne powiązania

Inicjalizacja bez struktury, która umożliwia pisanie

```cpp
auto [ x, y, z ] = expr;
```

 gdzie typ `expr` to obiekty podobne do krotek, których elementy byłyby powiązane ze zmiennymi `x`, `y` i `z` (które deklaruje ta konstrukcja).

 _Tuple-like objects_ include `std::tuple`, `std::pair`, `std::array` i struktury kruszywowe.

___
<!-- .slide: style="font-size: 0.95em" -->

## Strukturalne powiązania

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
    // Do something with key and value
}
```
<!-- .element: class="fragment fade-in" -->

___

## Ćwiczenie

Stworzyć `std::map<shared_ptr<Shape>, double>` który utrzyma kształt i jego obwód.

Użyj powiązań strukturalnych, aby iterować po tej kolekcji i wyświetlić informacje o kształcie (Call `print()` funkcja składowa) i obwód.
