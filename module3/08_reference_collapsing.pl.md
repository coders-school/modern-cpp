## Zwiń odniesienie

Gdy szablon jest tworzony, może wystąpić zwijanie odwołania

```cpp
template <typename T>
void f(T& item) {  // takes item always as an l-value reference
                    // whatever you pass
    // ...
}

void f(int& & item);   // passing int& as a param -> f(int&)
void f(int&& & item);  // passing int&& as a param -> f(int&)
```

### Reguły zwijania odwołań <!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>T& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T& &&</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &&</code> -> <code>T&&</code>
