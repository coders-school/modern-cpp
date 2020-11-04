## Pre-test

### Question 1/2

Take a pen ✏

```cpp
template <typename T>
void foo(T && a) {std::cout << "OK\n"; }

int a = 5;
```
<!-- .element: class="fragment fade-in" -->

We have only above template function defined.
What will happen in each case? Which example will compile and display "OK"?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>

Tell me when you are ready
<!-- .element: class="fragment fade-in" -->

___

## Pre-test

### Question 2/2

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

What will be printed in the screen? Take a pen and jot down your answers.
