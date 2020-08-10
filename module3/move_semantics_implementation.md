## Implementation of move semantic

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

## Implementation of move semantic

### Usual implementation

```cpp
class X : public Base {
    Member m_;

    X(X&& x) = default;
    X& operator=(X&& x) = default;
};
```

___

## Task

Aim: learn how to implement move semantics with manual resource management

Write your own implementation of `unique_ptr`

Let's try online Coding Dojo :)
<!-- .element: class="fragment highlight-green" -->

#### Hints

<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Template class
* <!-- .element: class="fragment fade-in" --> RAII
* <!-- .element: class="fragment fade-in" --> Copy operations not allowed
* <!-- .element: class="fragment fade-in" --> Move operations allowed
* <!-- .element: class="fragment fade-in" --> <a href="https://en.cppreference.com/w/cpp/memory/unique_ptr">Interface functions</a> - at least:
    * <code>T* get() const noexcept</code>
    * <code>T& operator*() const</code>
    * <code>T* operator->() const noexcept</code>
    * <code>void reset(T* = nullptr) noexcept</code>
