## Test wstępny

### Pytanie 1/2

Weź długopis ✏

```cpp
template <typename T>
void foo(T && a) {std::cout << "OK\n"; }

int a = 5;
```
<!-- .element: class="fragment fade-in" -->

Mamy zdefiniowaną tylko powyższą funkcję szablonu.
Co się stanie w każdym przypadku? Który przykład skompiluje się i wyświetli „OK”?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>

Powiedz mi kiedy będziesz gotowy
<!-- .element: class="fragment fade-in" -->

___

## Test wstępny

### Pytanie 2/2

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

Co zostanie wypisane na ekranie? Weź długopis i zanotuj swoje odpowiedzi.
