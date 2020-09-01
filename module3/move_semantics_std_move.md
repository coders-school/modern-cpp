## Implementation of `std::move()` and "universal reference"

```cpp
template <typename T>
typename std::remove_reference<T>::type&& move(T&& obj) noexcept {
    using ReturnType = std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(obj);
}
```

* <!-- .element: class="fragment fade-in" --> <code>T&&</code> as a template function parameter is not only r-value reference
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> is a "forwarding reference" or "universal reference" (name proposed by Scott Meyers)
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> in templates can bind to l-values and r-values
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> takes any kind of reference and cast it to r-value reference
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> convert any object into a temporary, so that it can be later matched by the compiler to be passed by an r-value reference
