<!-- .slide: style="font-size: 0.9em" -->
## Interface bloat

Próba optymalizacji dla każdego możliwego przypadku użycia może prowadzić do "rozdęcia" interfejsu (interface bloat)

```cpp
class Gadget;
void f(const Gadget&)     { std::cout << "const Gadget&\n"; }
void f(Gadget&)           { std::cout << "Gadget&\n"; }
void f(Gadget&&)          { std::cout << "Gadget&&\n"; }
void use(const Gadget& g) { f(g); }            // wywołuje f(const Gadget&)
void use(Gadget& g)       { f(g); }            // wywołuje f(Gadget&)
void use(Gadget&& g)      { f(std::move(g)); } // wywołuje f(Gadget&&)

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);       // wywołuje use(const Gadget&) potem wywołuje f(const Gadget&)
    use(g);        // wywołuje use(Gadget&) potem wywołuje f(Gadget&)
    use(Gadget()); // wywołuje use(Gadget&&) potem wywołuje f(Gadget&&)
}
```

Zadanie: spróbuj ulepszyć funkcję `use()`, aby złapać więcej typów referencji, zmniejszając w ten sposób liczbę przeciążeń.
<!-- .element: class="fragment fade-in" -->

___

## Perfect Forwarding

"Forwarding reference" `T&&` + `std::forward()` to rozwiązanie problemu "wzdęcia" interfejsu.

```cpp
class Gadget;

void f(const Gadget&) { std::cout << "const Gadget&\n"; }
void f(Gadget&)       { std::cout << "Gadget&\n"; }
void f(Gadget&&)      { std::cout << "Gadget&&\n"; }

template <typename Gadget>
void use(Gadget&& g) {
    f(std::forward<Gadget>(g)); // przekazuje oryginalny typ do f()
}

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);       // wywołuje use(const Gadget&) potem wywołuje f(const Gadget&)
    use(g);        // wywołuje use(Gadget&) potem wywołuje f(Gadget&)
    use(Gadget()); // wywołuje use(Gadget&&) potem wywołuje f(Gadget&&)
}
```

___
<!-- .slide: style="font-size: 0.9em" -->
## `std::forward`

"Forwarding reference" (powiązane nawet z r-value) jest traktowane jako l-value wewnątrz funkcji szablonu

```cpp
template <typename T>
void use(T&& t) {
    f(t);                   // t jest bezwarunkowo traktowane jako l-value
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void use(T&& t) {
    f(std::move(t));        // t jest bezwarunkowo traktowane jako r-value
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void use(T&& t) {           // przekaż t jako r-value, jeśli zostało przekazane r-value,
    f(std::forward(t));     // przekaż jako l-value w.p.p.
}
```
<!-- .element: class="fragment fade-in" -->

Innymi słowy: `std::forward()` przywraca oryginalny typ referencji.
<!-- .element: class="fragment fade-in" -->
