## Nadęty interfejs

Próba optymalizacji dla każdego możliwego przypadku użycia może prowadzić do rozdęcia interfejsu

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

Zadanie: spróbuj ulepszyć `use()` funkcja, aby złapać więcej typów odwołań, aby mieć mniej przeciążeń.
<!-- .element: class="fragment fade-in" -->

___

## Doskonałe przekazywanie

Odniesienie do przekazywania `T&&` + `std::forward()` to rozwiązanie problemu wzdęcia interfejsu.

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

Odniesienie do przekazywania (nawet powiązanie z wartością r) jest traktowane jako wartość l wewnątrz funkcji szablonu

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

Innymi słowy: `std::forward()` przywraca oryginalny typ odniesienia.
<!-- .element: class="fragment fade-in" -->
