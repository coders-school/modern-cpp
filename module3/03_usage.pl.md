## Wykorzystanie semantyki przenoszenia

```cpp
template <typename T>
class Container {
public:
    void insert(const T& item);  // inserts a copy of item
    void insert(T&& item);       // moves item into container
};

Container<std::string> c;
std::string str = "text";

c.insert(str);              // lvalue -> insert(const std::string&)
                            // inserts a copy of str, str is used later
c.insert(str + str);        // rvalue -> insert(string&&)
                            // moves temporary into container
c.insert("text");           // rvalue -> insert(string&&)
                            // moves temporary into container
c.insert(std::move(str));   // rvalue -> insert(string&&)
                            // moves str into container, str is no longer used
```

___

## Właściwości semantyki przenoszenia

* <!-- .element: class="fragment fade-in" --> Przenieś wszystkie dane od źródła do celu
* <!-- .element: class="fragment fade-in" --> Pozostaw obiekt źródłowy w nieznanym , ale bezpiecznym do usunięcia stanie
* <!-- .element: class="fragment fade-in" --> Obiekt źródłowy nigdy nie powinien być używany
* <!-- .element: class="fragment fade-in" --> Obiekt źródłowy można tylko bezpiecznie zwolnić lub, jeśli to możliwe, przypisać do niego nowy zasób (np. <code>reset()</code>)

```cpp
std::unique_ptr<int> pointer1{new int{5}};
std::unique_ptr<int> pointer2 = std::move(pointer1);
*pointer1 = 4;  // Undefined behavior, pointer1 is in moved-from state
pointer1.reset(new int{20});    // OK
```
<!-- .element: class="fragment fade-in" -->
