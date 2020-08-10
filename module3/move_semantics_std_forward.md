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

___

## Knowledge check 🙂

### Template type deduction

<pre><code class="cpp" data-trim data-noescape>
template &lt;typename T&gt;
void copy(T arg) {}

template &lt;typename T&gt;
void reference(T& arg) {}

template &lt;typename T&gt;
void universal_reference(T&& arg) {}

int main() {
    int number = 4;
    copy(number);       <span class="fragment">// int</span>
    copy(5);            <span class="fragment">// int</span>
    reference(number);  <span class="fragment">// int&</span>
    reference(5);       <span class="fragment">// candidate function [with T = int] not viable: expects an l-value for 1st argument</span>
    universal_reference(number);            <span class="fragment">// int&</span>
    universal_reference(std::move(number)); <span class="fragment">// int&&</span>
    universal_reference(5);                 <span class="fragment">// int&&</span>
}
</code></pre>
