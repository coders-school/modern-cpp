<!-- .slide: data-background="#111111" -->
# `static_assert`

___

## `static_assert`

```cpp
template <class T>
void swap(T& a, T& b)
{
    static_assert(std::is_copy_constructible<T>::value,
                  "Swap requires copying");
    static_assert(std::is_nothrow_move_constructible_v<T> &&
                  std::is_nothrow_move_assignable_v<T>);
    auto c = b;
    b = a;
    a = c;
}
```
<!-- .element: class="fragment fade-in" -->

**Motywacja**: Przerywa kompilację w przypadku nie spełnienia warunków zdefiniowanych przez programistę (zwykle nie spełnienie wymagań określonych typów).
<!-- .element: class="fragment fade-in" -->

Wykonuje sprawdzanie asercji w czasie kompilacji. Zwykle używany z biblioteką `<type_traits>`.
<!-- .element: class="fragment fade-in" -->

Wiadomość podawana jako drugi parametr jest opcjonalna od C++17.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Sprawdź, czy `M_PI` wykorzystane w pliku `Circle.cpp` nie jest równe `3.14`.

```cpp
static_assert(condition, "optional message");
```
