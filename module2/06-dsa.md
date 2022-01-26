<!-- .slide: data-background="#111111" -->
# Data structure alignment

## `alignas`, `alignof`

___

## `alignas` keyword

```c++
alignas(int) char variable;

// every object of type see_t will be aligned to 16-byte boundary
struct alignas(16) see_t {
    float see_data[4];
};

// error: requested alignment is not a positive power of 2
alignas(129) char cacheline[128];
```

___

## `alignas` keyword

The `alignas` specifier may be applied to:

- the declaration of variable or a class data member
- the declaration or definition of a class/struct/union or enumeration

`alignas(expression)` - expression needs to be positive power of 2.
<!-- .element: class="fragment fade-in" -->

`alignas(type-id)` - equivalent to `alignas(alignof(type-id))`
<!-- .element: class="fragment fade-in" -->

`alignas(0)` - has no effect
<!-- .element: class="fragment fade-in" -->

If `alignas` would weaken the alignment the type have had without this `alignas`, it will not be applied.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.8em" -->
## `alignof` keyword

The `alignof` specifier returns a value of type `std::size_t`, which is alignment in bytes. If the type is reference type, the operator returns the alignment of referenced type; if the type is array type, alignment requirement of the element type is returned.

<div style="display: flex;">

<div style="width: 420px" class="fragment fade-in">

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

<div style="width: 750px" class="fragment fade-in">

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

## Exercise

Change the alignment of the `Circle` class to 128.

Print the alignment in `main()` function.

Change the alignment to 2.

Print the alignment.
