## Pre-test 📝

___

### Pytanie 1/2

Mamy zdefiniowaną tylko poniższą funkcję szablonową.
Co się stanie w każdym z poniższych przypadków? Który z nich się skompiluje i wyświetli "OK"?

```cpp
template <typename T>
void foo(T && a) {std::cout << "OK\n"; }

int a = 5;
```

1. <code>foo(4);</code>
2. <code>foo(a);</code>
3. <code>foo(std::move(a));</code>

___

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
