## Sprawdzian wiedzy 🙂

### Odliczenie za typ szablonu

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

## Sprawdzian wiedzy 🤯

```cpp
void foo(int && a);         // r
void foo(int & a);          // l

int a = 5;
```

Która z powyższych funkcji zostanie wywołana przez poniższe fragmenty?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(4));</code>
  * r (ruch jest zbędny) <!-- .element: class="fragment fade-in" -->

___

## Sprawdzian wiedzy 🤯

```cpp
template <typename T>
void foo(T && a);         // r

template <typename T>
void foo(T & a);          // l

int a = 5;
```

Która z powyższych funkcji zostanie wywołana przez poniższe fragmenty?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" --> 
* <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" --> 
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" --> 

___

## Sprawdzian wiedzy 🤯

```cpp
template <typename T>
void foo(T && a);         // r

int a = 5;
```

Co się teraz stanie?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(a);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->

___

## Odpowiedzi przed testem

### Pytanie 1/2

* <!-- .element: class="fragment fade-in" --> "DOBRZE"
* <!-- .element: class="fragment fade-in" --> "DOBRZE"
* <!-- .element: class="fragment fade-in" --> "DOBRZE"

### Pytanie 2/2

* <!-- .element: class="fragment fade-in" --> <code>const Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
