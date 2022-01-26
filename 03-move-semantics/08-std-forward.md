<!-- .slide: style="font-size: 0.9em" -->

## Zaśmiecanie interfejsów

Gdy chcemy napisać kod, który jest optymalny dla każdego przypadku, trzeba napisać kilka przeciążeń do każdej funkcji.

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
<!-- .element: class="fragment fade-in" -->

### Czy można tego uniknąć?
<!-- .element: class="fragment fade-in" -->

___

### Zadanie

Ulepsz funkcję `use()`, aby mogła przechwycić różne rodzaje referencji i aby nie tworzyć aż tylu przeciążeń.
<!-- .element: class="fragment fade-in" -->

___

## Solution: Perfect Forwarding

`T&&` + `std::forward()` to rozwiązanie na zbytni rozrost interfejsów.
<!-- .element: class="fragment fade-in" -->

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
<!-- .element: class="fragment fade-in" -->

___

## `std::forward`

Referencja przekazująca (forwarding reference), nawet do r-value, jest traktowana jako l-value wewnątrz funkcji szablonowych.

```cpp
template <typename T>
void use(T&& t) {
    f(t);                   // t treated as l-value unconditionally
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void use(T&& t) {
    f(std::move(t));        // t treated as r-value unconditionally
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
template <typename T>
void use(T&& t) {           // forwards t as r-value if r-value was passed,
    f(std::forward<T>(t));  // forwards as l-value otherwise
}
```
<!-- .element: class="fragment fade-in" -->

Innymi słowy, `std::forward()` przywraca oryginalny typ referencji.
<!-- .element: class="fragment fade-in" -->
