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

___

## Knowledge check 🤯

```cpp
void foo(int && a);         // r
void foo(int & a);          // l

int a = 5;
```

Which of above functions will be called by below snippets?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(4));</code>
  * r (move is redundant) <!-- .element: class="fragment fade-in" -->

___

## Knowledge check 🤯

```cpp
template <typename T>
void foo(T && a);         // r

template <typename T>
void foo(T & a);          // l

int a = 5;
```

Which of above functions will be called by below snippets?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" --> 
* <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" --> 
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" --> 

___

## Knowledge check 🤯

```cpp
template <typename T>
void foo(T && a);         // r

int a = 5;
```

What will happen now?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(a);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->

___

## Pre-test answers

### Question 1/2

* <!-- .element: class="fragment fade-in" --> "OK"
* <!-- .element: class="fragment fade-in" --> "OK"
* <!-- .element: class="fragment fade-in" --> "OK"

### Question 2/2

* <!-- .element: class="fragment fade-in" --> <code>const Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
