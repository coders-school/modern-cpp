## Wdrożenie `std::move()` i „uniwersalne odniesienie”

```cpp
template <typename T>
typename std::remove_reference<T>::type&& move(T&& obj) noexcept {
    using ReturnType = std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(obj);
}
```

* <!-- .element: class="fragment fade-in" --> <code>T&&</code> jako parametr funkcji szablonu jest nie tylko odniesieniem do wartości r
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> to „odniesienie do przekazywania” lub „odniesienie uniwersalne” (nazwa zaproponowana przez Scotta Meyersa)
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> w szablonach może wiązać się z l-wartościami i r-wartościami
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> przyjmuje dowolny rodzaj odniesienia i rzutuje go na odniesienie do wartości r
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> przekonwertować dowolny obiekt na tymczasowy, aby mógł zostać później dopasowany przez kompilator do przekazania przez odniesienie do wartości r
