<!-- .slide: data-background="#111111" -->
# `nullptr`

___

## Porównanie wskaźników

```cpp
int* p1 = nullptr;
int* p2 = NULL;
int* p3 = 0;

p2 == p1; // true
p3 == p1; // true

int* p {}; // p is set to nullptr
```

___

## Overload resolution - wybór przeciążenia funkcji

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

* <!-- .element: class="fragment fade-in" --> wartość wskaźnika, który na nic nie wskazuje
* <!-- .element: class="fragment fade-in" --> bardziej ekspresyjny i bezpieczniejszy zapis niż stała <code>NULL/0</code>
* <!-- .element: class="fragment fade-in" --> ma zdefiniowany typ <code>std::nullptr_t</code>
* <!-- .element: class="fragment fade-in" --> rozwiązuje problem z przeciążonymi funkcjami, które jako argument przyjmują wskaźnik lub liczbę całkowitą
