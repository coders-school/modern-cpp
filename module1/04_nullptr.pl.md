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

int* p {}; // p ma wartość nullptr
```

___

## Overload resolution - wybieranie przeciążonych funkcji
<!-- nie wiedziałem jak przetłumaczyć to pojęcie, na internecie też niczego nie mogłem znaleźć -->

```cpp
void foo(int);

foo(0);        // wywołuje foo(int)
foo(NULL);     // wywołuje foo(int)
foo(nullptr);  // compile time error
```
<!-- .element: class="fragment fade-in" -->

```cpp
void bar(int);
void bar(void*);
void bar(std::nullptr_t);

bar(0);        // wywołuje bar(int)
bar(NULL);     // wywołuje bar(int) jeśli NULL to 0, może być dwuznaczny jeśli NULL to 0L
bar(nullptr);  // wywołuje bar(std::nullptr_t) jeśli jest zdefiniowane, w przeciwnym przypadku bar(void*)
```
<!-- .element: class="fragment fade-in" -->

___

## `nullptr`

* <!-- .element: class="fragment fade-in" --> wartość wskaźnika, który na nic nie wskazuje
* <!-- .element: class="fragment fade-in" --> bardziej wyrazisty i bezpieczniejszy niż stała <code>NULL/0</code>
* <!-- .element: class="fragment fade-in" --> ma zdefiniowany typ <code>std::nullptr_t</code>
* <!-- .element: class="fragment fade-in" --> rozwiązuje problem z przeciążonymi funkcjami, które jako argument przyjmują wskaźnik lub liczbę całkowitą
