<!-- .slide: data-background="#111111" -->
# Other useful features

___

## Nested namespace definitions (C++17)

You can nest namespaces like this:

```c++
namespace A::B::C {
  ...
}
```

Instead of this:

```c++
namespace A {
  namespace B {
    namespace C {
      ...
    }
  }
}
```
<!-- Sentence which was here befor haven't felt right for me, so I've changed it. -->
___

## Class template argument deduction (C++17)

From C++17 class template arguments can be deduced automatically. Automatic template argument deduction was available earlier only for template functions.

```c++
std::pair p(1, 'x'); // C++17: OK, C++14: error: missing
                     //template arguments before p
std::pair<int, std::string> p(1, 'x'); // C++14: OK
auto p = std::make_pair(1, 'x'); // C++17: OK, C++14: OK
```

___

## Selection statements with initializer (C++17)

New versions of the `if` and `switch` statements for C++:

### `if (init; condition)`

```cpp
status_code foo() { // C++14
    { //variable c scope
        status_code c = bar();
        if (c != SUCCESS) {
            return c;
        }
    }
    // ...
}
```

___

## `switch (init; condition)`

```cpp
status_code foo() { // C++17
    if (status_code c = bar(); c != SUCCESS) {
        return c;
    }
    // ...
}
```

___

## Selection statements with initializer (C++17)

```c++
{
    Foo gadget(args);
    switch (auto s = gadget.status()) { // C++14
        case OK: gadget.zip(); break;
        case Bad: throw BadFoo(s.message());
    }
}
```

```c++
switch (Foo gadget(args); auto s = gadget.status()) { // C++17
    case OK: gadget.zip(); break;
    case Bad: throw BadFoo(s.message());
}
```

___

## Overview

[Overview of modern C++ features](https://github.com/AnthonyCalandra/modern-cpp-features#stdfilesystem)
