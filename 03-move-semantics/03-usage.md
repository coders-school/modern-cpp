<!-- .slide: style="font-size: 0.9em" -->

## Użycie semantyki przenoszenia

```cpp
template <typename T>
class Container {
    // ...
public:
    // void insert(T item);         // inserts a copy of an item (3 copies)
    void insert(const T& item);  // inserts a copy of an item (2 copies)
    void insert(T&& item);       // moves item into the container (1 copy)
};

Container<std::string> c;
std::string str = "text";

c.insert(str);              // lvalue -> insert(const std::string&)
                            // inserts a copy of str, str is used later
c.insert(str + str);        // rvalue -> insert(string&&)
                            // moves temporary into the container
c.insert("text");           // rvalue -> insert(string&&)
                            // moves temporary into the container
c.insert(std::move(str));   // rvalue -> insert(string&&)
                            // moves str into the container, str should not be used
```

___

## Własności semantyki przenoszenia

* <!-- .element: class="fragment fade-in" --> Transferuje wszystkie dane z obiektu źródłowego do docelowego
* <!-- .element: class="fragment fade-in" --> Pozostawia obiekt źródłowy w nieznanym, ale bezpiecznym do usunięcia stanie
* <!-- .element: class="fragment fade-in" --> Obiekt źródłowy po przeniesieniu nie powinien być już używany
* <!-- .element: class="fragment fade-in" --> Obiekt źródłowy po przeniesieniu może zostać bezpiecznie zniszczony lub można mu przypisać nowy zasób (np. <code>reset()</code> w smart pointerach)

```cpp
std::unique_ptr<int> pointer1{new int{5}};
std::unique_ptr<int> pointer2 = std::move(pointer1);
*pointer1 = 4;  // Undefined behavior, pointer1 is in the moved-from state
pointer1.reset(new int{20});    // OK
```
<!-- .element: class="fragment fade-in" -->
