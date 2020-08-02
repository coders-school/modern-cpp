<!-- .slide: data-background="#111111" -->
# Data structure alignment (`alignas`, `alignof`)

___

### _`alignas`_ keyword

The `alignas` specifier may be applied to:

- the declaration of variable or a class data member
- the declaration or definition of a class/struct/union or enumeration

`alignas(expression)` - expression needs to be positive power of 2.

`alignas(type-id)` - equivalent to `alignas(alignof(type-id))`

`alignas(0)` - has no effect

**Exception:** if `alignas` would weaken the alignment the type have had without this `alignas`, it will not be applied. <!-- bolded "exceptions" to make it stand out more -->

___

### _`alignas`_ keyword

```c++
// every object of type see_t will be alignet to 16-byte boundary
struct alignas(16) see_t {
    float see_data[4];
};

// error: requested alignment is not a positive power of 2 alignas(129) char cacheline[128];
alignas(129) char cacheline[128];
```

___

##### _`alignof`_ keyword

The `alignof` specifier returns a value of type `std::size_t`, which is alignment in bytes. If the type is reference type, the operator returns the alignment of referenced type; if the type is array type, alignment requirement of the element type is returned.

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

## Exercise

Change the alignment of the `Circle` class to 128.

Print the alignment in `main()` function.

Change the alignment to 2.

Print the alignment.
