## Reference collapsing

When a template is being instantiated reference collapsing may occur

```cpp
template <typename T>
void f(T& item) {  // takes item always as an l-value reference
                    // whatever you pass
    // ...
}

void f(int& & item);   // passing int& as a param -> f(int&)
void f(int&& & item);  // passing int&& as a param -> f(int&)
```

### Reference collapsing rules <!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>T& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T& &&</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &&</code> -> <code>T&&</code>
