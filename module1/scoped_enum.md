<!-- .slide: data-background="#111111" -->
# Scoped `enum`

___

## Standard `enum`

```cpp
enum Colors {
    RED = 10,
    ORANGE,
    GREEN
};

Colors a = RED;     // OK
int b = GREEN;      // OK

enum Fruits {
    ORANGE,
    BANANA
};

Colors c = ORANGE;  // 11 or 0?
// Hopefully: error: ‘ORANGE’ conflicts with a previous declaration
```

___

## `enum class`

```cpp
enum class Languages {
    ENGLISH,
    GERMAN,
    POLISH
};

Languages a = Languages::ENGLISH;
// Languages b = GERMAN;
// int c = Languages::ENGLISH;
int d = static_cast<int>(Languages::ENGLISH);   // only explicit cast allowed
```
<!-- .element: class="fragment fade-in" -->

**Rationale**: Stronger and less error-prone enumeration types.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Introduced in C++11
* <!-- .element: class="fragment fade-in" --> Restricts range of defined constants only to those defined in an enum class
* <!-- .element: class="fragment fade-in" --> Enum values must be accessed with the enum name scope
* <!-- .element: class="fragment fade-in" --> Does not allow implicit conversions, <code>static_cast</code> must be used
* <!-- .element: class="fragment fade-in" --> <code>enum class == enum struct</code>

___

## `enum` base

```cpp
#include <iostream>
#include <limits>

enum Colors   { YELLOW = 10, ORANGE };
enum BigValue { VALUE = std::numeric_limits<long>::max() };
enum RgbColors : unsigned char {
    RED = 0x01,
    GREEN = 0x02,
    BLUE = 0x04,
    // BLACK = 0xFF + 1  // error: enumerator value 256 is outside
};                       // the range of underlying type ‘unsigned char’

int main() {
    std::cout << sizeof(Colors) << std::endl;    // 4 - sizeof(int)
    std::cout << sizeof(BigValue) << std::endl;  // 8 - sizeof(long)
    std::cout << sizeof(RgbColors) << std::endl; // 1 - sizeof(unsigned char)
    return 0;
}
```

[Change the code in ideone.com](https://ideone.com/e.js/8sR1XK)

___

## `enum` size

* <!-- .element: class="fragment fade-in" --> Default enum size is <code>sizeof(int)</code>
* <!-- .element: class="fragment fade-in" --> <code>enum</code> underlying type is extended automatically if values greater than <code>int</code> are provided
* <!-- .element: class="fragment fade-in" --> To save some memory we can define the underlying type using inheritance
* <!-- .element: class="fragment fade-in" --> A compiler will not allow defining value greater than the defined base can hold
* <!-- .element: class="fragment fade-in" --> Inheritance work on both <code>enum</code> and <code>enum class</code>

___

## `enum` forward declaration

For enums with the defined underlying type, it is possible to provide only a forward declaration, if values do not need to be known.
<!-- .element: class="fragment fade-in" -->

There will be no need to recompile source file if new enum values are added.
<!-- .element: class="fragment fade-in" -->

```cpp
enum Colors : unsigned int;
enum struct Languages : unsigned char;
```
<!-- .element: class="fragment fade-in" -->

___

## Exercise

Write a new scoped enum named `Color` and define in it 3 colors of your choice.

Inherit from `unsigned char`.

Add a new field: `Color color` in the `Shape` class, so that every shape can have its own defined color.

Add a default color value in a Shape class.
