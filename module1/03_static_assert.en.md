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

**Rationale**: Preventing compilation on user defined conditions (usually specific types).
<!-- .element: class="fragment fade-in" -->

Performs compile-time assertion checking. Usually used with `<type_traits>` library.
<!-- .element: class="fragment fade-in" -->

The message is optional from C++17.
<!-- .element: class="fragment fade-in" -->

___

## Exercise

Assert that `M_PI` used in `Circle.cpp` file is not equal to `3.14`

```cpp
static_assert(condition, "optional message");
```
