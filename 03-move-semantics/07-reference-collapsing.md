## Reference collapsing rules

* <!-- .element: class="fragment fade-in" --> <code>T& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T& &&</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &&</code> -> <code>T&&</code>

___

## Reference collapsing

Zwijanie referencji odbywa się gdy kompilator generuje instancje szablonów

```cpp
template <typename T>
void f(T & item) {}    // takes item always as an l-value reference

void f(int& & item);   // passing int& as a param, like f(a) -> f(int&)
void f(int&& & item);  // passing int&& as a param, like f(5) -> f(int&)
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void g(T && item) {}   // takes item as a forwarding reference

void g(int& && item);  // passing int& as a param, like g(a) -> f(int&)
void g(int&& && item); // passing int&& as a param, like g(5) -> f(int&&)
```
<!-- .element: class="fragment fade-in" -->
