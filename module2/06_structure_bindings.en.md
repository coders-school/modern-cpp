<!-- .slide: data-background="#111111" -->
# Structured bindings
<!-- I haven't found enything in presentation you've send me with e-mail, so I've searched in repo from C++ course I was participating in, and put those informations here. If I missed something in your's presentatnion in PDF than, please, tell me witch slides to put here or if I should leave it blank. -->
___

## Structured bindings

De-structuring initialization, that allows writting

```cpp
auto [ x, y, z ] = expr;
```

 where the type of `expr` is tuple-like objects, whose elements would be bound to the variables `x`, `y` and `z` (which this construct declares).

 _Tuple-like objects_ include `std::tuple`, `std::pair`, `std::array` and aggregate structures.

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
    // Do something with key and value
}
```
<!-- .element: class="fragment fade-in" -->

___

## Exercise

Create an `std::map<shared_ptr<Shape>, double>` that will hold a shape and it's perimeter.

Use structured bindings to iterate over this collection and display shape info (call `print()` member function) and a perimeter.
