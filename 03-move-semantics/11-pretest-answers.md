## Pre-test 📝

### Odpowiedzi

___

### Pytanie 1/2

Mamy zdefiniowaną tylko poniższą funkcję szablonową.
Co się stanie w każdym z poniższych przypadków? Który z nich się skompiluje i wyświetli "OK"?

```cpp
template <typename T>
void foo(T && a) {std::cout << "OK\n"; }

int a = 5;
```

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
  * <!-- .element: class="fragment fade-in" --> "OK"
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
  * <!-- .element: class="fragment fade-in" --> "OK"
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>
  * <!-- .element: class="fragment fade-in" --> "OK"

___
<!-- .slide: style="font-size: 0.9em" -->

### Pytanie 2/2

Co wyświetli się na ekranie?

```cpp
class Gadget {};
void f(const Gadget&) { std::cout << "const Gadget&\n"; }
void f(Gadget&)       { std::cout << "Gadget&\n"; }
void f(Gadget&&)      { std::cout << "Gadget&&\n"; }

template <typename Gadget>
void use(Gadget&& g) { f(g); }

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);
    use(g);
    use(Gadget());
}
```

* <!-- .element: class="fragment fade-in" --> <code>const Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
