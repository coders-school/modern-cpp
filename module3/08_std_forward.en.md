## Interface bloat

Trying to optimize for every possible use case may lead to an interface bloat

```cpp
class Gadget;
void f(const Gadget&)     { std::cout << "const Gadget&\n"; }
void f(Gadget&)           { std::cout << "Gadget&\n"; }
void f(Gadget&&)          { std::cout << "Gadget&&\n"; }
void use(const Gadget& g) { f(g); }            // calls f(const Gadget&)
void use(Gadget& g)       { f(g); }            // calls f(Gadget&)
void use(Gadget&& g)      { f(std::move(g)); } // calls f(Gadget&&)

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);       // calls use(const Gadget&) then calls f(const Gadget&)
    use(g);        // calls use(Gadget&) then calls f(Gadget&)
    use(Gadget()); // calls use(Gadget&&) then calls f(Gadget&&)
}
```

Task: Try to improve the `use()` function to catch more types of reference to have less overloads.
<!-- .element: class="fragment fade-in" -->

___

## Perfect Forwarding

Forwarding reference `T&&` + `std::forward()` is a solution to interface bloat.

```cpp
class Gadget;

void f(const Gadget&) { std::cout << "const Gadget&\n"; }
void f(Gadget&)       { std::cout << "Gadget&\n"; }
void f(Gadget&&)      { std::cout << "Gadget&&\n"; }

template <typename Gadget>
void use(Gadget&& g) {
    f(std::forward<Gadget>(g)); // forwards original type to f()
}

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);       // calls use(const Gadget&) then calls f(const Gadget&)
    use(g);        // calls use(Gadget&) then calls f(Gadget&)
    use(Gadget()); // calls use(Gadget&&) then calls f(Gadget&&)
}
```

___

## `std::forward`

Forwarding reference (even bind to r-value) is treated as l-value inside template function

```cpp
template <typename T>
void use(T&& t) {
    f(t);                   // t is treated as l-value unconditionally
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void use(T&& t) {
    f(std::move(t));        // t is treated as r-value unconditionally
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void use(T&& t) {           // pass t as r-value if r-value was passed,
    f(std::forward(t));     // pass as l-value otherwise
}
```
<!-- .element: class="fragment fade-in" -->

In other words: `std::forward()` restores original reference type.
<!-- .element: class="fragment fade-in" -->
