## Implementacja `std::move()`


```cpp
template <typename T>
typename std::remove_reference<T>::type&& move(T&& obj) noexcept {
    using ReturnType = typename std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(obj);
}
```
<!-- .element: class="fragment fade-in" -->

___

## Forwarding reference

### "Uniwersalna referencja"
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>T&&</code> jako parametr szablonowy nie oznacza tylko referencji do r-value
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> to "forwarding reference" lub "universal reference" (nazwa zaproponowana przez Scotta Meyersa)
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> w szablonach obsługuje zarówno l-value i r-value
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> przyjmuje dowolny typ referencji i konwertuje go na referencję do r-value
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> konwertuje dowolny obiekt w obiekt tymczasowy, który jest później dopasowany przez kompilator do przeciążeń funkcji przyjmujących referencję do r-value
