## Usage of move semantics

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

## Properties of move semantics

* <!-- .element: class="fragment fade-in" --> Transfer all data from the source to the target
* <!-- .element: class="fragment fade-in" --> Leave the source object in an unknown, but safe to delete state
* <!-- .element: class="fragment fade-in" --> The source object should never be used
* <!-- .element: class="fragment fade-in" --> The source object can only be safely destroyed or, if possible, new resource can be assigned to it (eg. <code>reset()</code>)

```cpp
std::unique_ptr<int> pointer1{new int{5}};
std::unique_ptr<int> pointer2 = std::move(pointer1);
*pointer1 = 4;  // Undefined behavior, pointer1 is in moved-from state
pointer1.reset(new int{20});    // OK
```
<!-- .element: class="fragment fade-in" -->
