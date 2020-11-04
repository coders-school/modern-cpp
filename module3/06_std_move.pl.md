## Implementacja `std::move()` i referencji uniwersalnej

```cpp
template <typename T>
typename std::remove_reference<T>::type&& move(T&& obj) noexcept {
    using ReturnType = std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(obj);
}
```

* <!-- .element: class="fragment fade-in" --> <code>T&&</code> jako parametr funkcji szablonu jest nie tylko referencją do r-value
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> to „forwarding reference” lub "universal reference” (nazwa zaproponowana przez Scotta Meyersa)
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> w szablonach może wiązać się z l-values i r-values
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> przyjmuje dowolny rodzaj referencji i rzutuje go na referencję do r-value
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> konwertuje dowolny obiekt na tymczasowy, aby mógł zostać później dopasowany przez kompilator do przekazania przez referencję do r-value
