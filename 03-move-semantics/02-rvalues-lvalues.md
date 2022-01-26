# Semantyka przenoszenia

## Motywacja

* Lepsza optymalizacja przez unikanie zbędnych kopii
* Ulepszone bezpieczeństwo poprzez zapewnienie tylko jednej instancji obiektu

___

## Nowe elementy składni

* <!-- .element: class="fragment fade-in" --> <code>auto && value</code> - r-value reference
* <!-- .element: class="fragment fade-in" --> <code>Class(Class &&)</code> - move constructor
* <!-- .element: class="fragment fade-in" --> <code>Class& operator=(Class&&)</code> - move assignment operator
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> auxilary function
* <!-- .element: class="fragment fade-in" --> <code>std::forward()</code> auxilary function

___

## r-value, l-value

```cpp
struct A { int a, b; };

A foo() { return {1, 2}; }

A a;                    // l-value
A{5, 3};                // r-value
foo();                  // r-value
```

___

## r-value, l-value

* <!-- .element: class="fragment fade-in" --> obiekty l-value mają nazwę i adres
* <!-- .element: class="fragment fade-in" --> obiekty l-value są trwałe, w kolejnej linii kodu można się do nich odwołać
* <!-- .element: class="fragment fade-in" --> obiekty r-value nie mają nazwy (zazwyczaj) ani adresu
* <!-- .element: class="fragment fade-in" --> obiekty r-value są tymczasowe, w kolejnej linii kodu nie można się do nich odwołać

___

## r-value and l-value references

```cpp
struct A { int a, b; };
A foo() { return {1, 2}; }

A a;                    // l-value
A{5, 3};                // r-value
foo();                  // r-value

A & ra = a;             // l-value reference to l-value, OK
A & rb = foo();         // l-value reference to r-value, ERROR
A const& rc = foo();    // const l-value reference to r-value, OK (exception)

A && rra = a;           // r-value reference to l-value, ERROR
A && rrb = foo();       // r-value reference to r-value, OK

A ca{20, 40};
A const&& rrc = ca;     // const r-value reference to l-value, ERROR
```
<!-- .element: style="font-size: 0.58em" -->

___

## r-value czy l-value?

<pre><code class="cpp" data-trim data-noescape>
str1 + str2                     <span class="fragment">// r-value</span>
str1 += str2                    <span class="fragment">// l-value</span>
[](int x){ return x * x; };     <span class="fragment">// r-value</span>
std::move(a);                   <span class="fragment">// r-value</span>
int && a = 4;                   <span class="fragment">// 4 is an r-value, a is an l-value</span>
</code></pre>

___

## referencja do r-value to... l-value?

### `int && a = 4;`

* <!-- .element: class="fragment fade-in" --> <code>4</code> to r-value
* <!-- .element: class="fragment fade-in" --> <code>a</code> to referencja do r-value
* <!-- .element: class="fragment fade-in" --> samo <code>a</code> jest jednak l-value - ma adres i nazwę, można się później do niego odnosić
* <!-- .element: class="fragment fade-in" --> ale na razie o tym nie myśl 😉

___

<!-- .slide: data-background-iframe="https://en.cppreference.com/w/cpp/language/value_category" data-background-interactive -->

<div class="box" style="position: absolute; width: 45%; right: 0; background-color: rgba(0, 0, 0, 0.9); color: #fff; padding: 20px; font-size: 20px; text-align: left;">
    <h2>Value categories in C++</h2>
    <ul>
        <li>lvalue</li>
        <li>prvalue</li>
        <li>xvalue</li>
        <li>glvalue = lvalue | xvalue</li>
        <li>rvalue = prvalue | xvalue</li>
    </ul>
    <p><a href="https://en.cppreference.com/w/cpp/language/value_category">Full list at cppreference.com</a></p>
</div>
