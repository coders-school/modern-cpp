<!-- .slide: data-background="#111111" -->
# `nullptr`

___

## Pointer comparison

```cpp
int* p1 = nullptr;
int* p2 = NULL;
int* p3 = 0;

p2 == p1; // true
p3 == p1; // true

int* p {}; // p is set to nullptr
```

___

## Overload resolution

```cpp
void foo(int);

foo(0);        // calls foo(int)
foo(NULL);     // calls foo(int)
foo(nullptr);  // compile time error
```
<!-- .element: class="fragment fade-in" -->

```cpp
void bar(int);
void bar(void*);
void bar(std::nullptr_t);

bar(0);        // calls bar(int)
bar(NULL);     // calls bar(int) if NULL is 0, may be ambiguous if NULL is 0L
bar(nullptr);  // calls bar(std::nullptr_t) if provided, bar(void*) otherwise
```
<!-- .element: class="fragment fade-in" -->

___

## `nullptr`

* <!-- .element: class="fragment fade-in" --> value for a pointer that points to nothing
* <!-- .element: class="fragment fade-in" --> more expressive and safer than <code>NULL/0</code> constant
* <!-- .element: class="fragment fade-in" --> has defined type <code>std::nullptr_t</code>
* <!-- .element: class="fragment fade-in" --> solves the problem with overloaded functions taking a pointer or an integer as an argument
