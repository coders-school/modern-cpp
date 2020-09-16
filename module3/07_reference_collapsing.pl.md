## Reference collapsing

Gdy szablon jest tworzony, może nastąpić "reference collapsing" - zredukowanie referencji.

```cpp
template <typename T>
void f(T& item) {  // zawsze pobiera wartość jako referencję do l-value
                    // nieważne co zostanie przekazane
    // ...
}

void f(int& & item);   // przekazanie int& jako parametr -> f(int&)
void f(int&& & item);  // przekazanie int&& jako parametr -> f(int&)
```

### Reguły redukowania referencji: <!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>T& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T& &&</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &&</code> -> <code>T&&</code>
