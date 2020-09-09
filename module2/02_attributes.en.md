<!-- .slide: data-background="#111111" -->
# Attributes

___
<!-- .slide: style="font-size: 0.9em" -->

## Attributes

Attributes provide the unified standard syntax for implementation-defined language extensions,
such as the GNU and IBM language extensions `__attribute__((...))`, Microsoft extension `declspec()`, etc.

### Standard attributes
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>[[noreturn]]</code> - function does never return, like <code>std::terminate</code>. If it does, we have UB
* <!-- .element: class="fragment fade-in" --> <code>[[deprecated]]</code> (C++14) - function is deprecated
* <!-- .element: class="fragment fade-in" --> <code>[[deprecated("reason")]]</code> (C++14) - as above, but compiler will emit the reason
* <!-- .element: class="fragment fade-in" --> <code>[[fallthrough]]</code> (C++17) - in <code>switch</code> statement, indicated that fall through is intentional
* <!-- .element: class="fragment fade-in" --> <code>[[nodiscard]]</code> (C++17) - you cannot ignore value returned from function
* <!-- .element: class="fragment fade-in" --> <code>[[maybe_unused]]</code> (C++17) - suppress compiler warning on unused class, typedef, variable, function, etc.

<!-- Problem with backticks if fadeing inplemented like this -->
___

## `[[noreturn]]` attribute

```c++
[[noreturn]] void f() {
    throw "error";
    // OK
}

[[noreturn]] void q(int i) {
    if (i > 0) {
        throw "positive";
    }
    // the behavior is undefined if called with argument <=0
}
```

___

## `[[fallthrough]]` attribute

```c++
void f(int n){
    void g(), h(), i();
    switch(n) {
    case 1:
    case 2:
        g();
        [[fallthrough]];
    case 3: // no warning on fallthrough
        h();
    case 4: // compiler may warn on fallthrough
        i();
        [[fallthrough]]; // illformed, not before a case label
    }
}
```

___

## `[[nodiscard]]` attribute

```c++
struct [[nodiscard]] error_info {};
error_info process(Data*);

// ...

void passMessage() {
    auto data = getData();
    process(data);  // compiler warning, discarding error_info
}
```

___

## `[[maybe_unused]]` attributes

```c++
[[maybe_unused]] void f([[maybe_unused]] bool thing1,
                        [[maybe_unused]] bool thing2)
{
  [[maybe_unused]] bool b = thing1 && thing2;
  assert (b); // in release mode, assert is compiled out, and b is unused
              // no warning because it is declared [[maybe_unused]]
} // parameters thing1 and thing2 are not used, no warning
```

___

## `[[deprecated]] attribute`

Attributes for namespaces and enumerators are available from C++17.

```c++
[[deprecated("Please use f2 instead")]] int f1();

enum E {
    foobar = 0,
    boobat [[deprecated]] = foobar
};
E e = foobat; // Emits warning

namespace [[deprecated]] old_stuff {
    void legacy();
}
old_stuff::legacy(); //Emits warning
```

___

## Exercise

Add a new method `double getPi()` in `Circle` class, which returns a PI number. Mark it as deprecated.
