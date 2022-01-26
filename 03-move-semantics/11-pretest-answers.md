## Pre-test answers 📝

___

### Question 1/2

We have only the below template function defined.
What will happen in each case? Which example will compile and display "OK"?

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

### Question 2/2

What will be printed on the screen?

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
