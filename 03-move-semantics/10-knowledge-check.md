<!-- .slide: style="font-size: 0.9em" -->

## Sprawdźmy wiedzę 🙂

### Dedukcja typów szablonowych

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

___

## Sprawdźmy wiedzę 🤯

```cpp
void foo(int && a);         // r
void foo(int & a);          // l

int a = 5;
```

Które z powyższych funkcji zostaną wywołane przez poniższe fragmenty kodu?

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(4));</code>
  * r (move is redundant) <!-- .element: class="fragment fade-in" -->

___

## Sprawdźmy wiedzę 🤯

```cpp
template <typename T>
void foo(T && a);         // r

template <typename T>
void foo(T & a);          // l

int a = 5;
```

Które z powyższych funkcji zostaną wywołane przez poniższe fragmenty kodu?

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->

___

## Sprawdźmy wiedzę 🤯

```cpp
template <typename T>
void foo(T && a);         // r

int a = 5;
```

Co się stanie teraz?

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->
