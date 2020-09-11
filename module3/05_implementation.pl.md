## Implementacja semantyki ruchu

```cpp
class X : public Base {
    Member m_;

    X(X&& x) : Base(std::move(x)), m_(std::move(x.m_)) {
        x.set_to_resourceless_state();
    }

    X& operator=(X&& x) {
        Base::operator=(std::move(x));
        m_ = std::move(x.m_);
        x.set_to_resourceless_state();
        return *this;
    }

    void set_to_resourceless_state() { /* reset pointers, handlers, etc. */ }
};
```

___

## Implementacja semantyki ruchu

### Zwykła implementacja

```cpp
class X : public Base {
    Member m_;

    X(X&& x) = default;
    X& operator=(X&& x) = default;
};
```

___

## Zadanie

Cel: naucz się implementować semantykę przenoszenia z ręcznym zarządzaniem zasobami

Napisz własną implementację `unique_ptr`

Spróbujmy online Coding Dojo :)
<!-- .element: class="fragment highlight-green" -->

#### Wskazówki

<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Klasa szablonu
* <!-- .element: class="fragment fade-in" --> RAII
* <!-- .element: class="fragment fade-in" --> Kopiowanie niedozwolone
* <!-- .element: class="fragment fade-in" --> Dozwolone operacje przenoszenia
* <!-- .element: class="fragment fade-in" --> <a href="https://en.cppreference.com/w/cpp/memory/unique_ptr">Funkcje interfejsu</a> - przynajmniej:
    * <code>T* get() const noexcept</code>
    * <code>T& operator*() const</code>
    * <code>T* operator->() const noexcept</code>
    * <code>void reset(T* = nullptr) noexcept</code>
