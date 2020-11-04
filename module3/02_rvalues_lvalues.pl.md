<!-- .slide: data-background="#111111" -->
# Semantyka przenoszenia

___

## Semantyka przenoszenia

* Lepsza optymalizacja dzięki unikaniu zbędnych kopii
* zwiększone bezpieczeństwo dzięki zachowaniu tylko jednej instancji

___

## Nowe elementy składni

* <!-- .element: class="fragment fade-in" --> <code>auto && value</code> - referencja do r-value (wartości prawostronnej)
* <!-- .element: class="fragment fade-in" --> <code>Class(Class &&)</code> - konstruktor przenoszący
* <!-- .element: class="fragment fade-in" --> <code>Class& operator=(Class&&)</code> - przenoszący operator przypisania
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> funkcja pomocnicza
* <!-- .element: class="fragment fade-in" --> <code>std::forward()</code> funkcja pomocnicza

___

## r-value i l-value

```cpp
struct A { int a, b; };

A foo() { return {1, 2}; }

A a;                    // l-value
A{5, 3};                // r-value
foo();                  // r-value
```

___

## r-value i l-value

* <!-- .element: class="fragment fade-in" --> Obiekt l-value ma nazwę i adres
* <!-- .element: class="fragment fade-in" --> Obiekt l-value jest trwały, w następnej linii można uzyskać do niego dostęp po nazwie
* <!-- .element: class="fragment fade-in" --> Obiekt r-value nie ma nazwy (zwykle) ani adresu
* <!-- .element: class="fragment fade-in" --> Obiekt r-value jest tymczasowy, w następnej linii nie będzie dostępny

___

## Referencje do r-value i l-value

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

A const ca{20, 40};
A const&& rrc = ca;     // const r-value reference to const l-value, ERROR
```

___

## r-value czy l-value?

<pre><code class="cpp" data-trim data-noescape>
str1 += str2                    <span class="fragment">// l-value</span>
str1 + str2                     <span class="fragment">// r-value</span>
[](int x){ return x * x; };     <span class="fragment">// r-value</span>
std::move(a);                   <span class="fragment">// r-value</span>
int && a = 4;                   <span class="fragment">// 4 is r-value</span>
</code></pre>

___

## referencja do r-value to ... l-value?

### `int && a = 4;`

* <!-- .element: class="fragment fade-in" --> <code>4</code> to r-value
* <!-- .element: class="fragment fade-in" --> <code>a</code> to referencja do r-value
* <!-- .element: class="fragment fade-in" --> sama nazwa <code>a</code> to l-value (ma adres, można się do niej odwoływać później)
* <!-- .element: class="fragment fade-in" --> ale nie myślmy o tym teraz 😉

___

<!-- .slide: data-background-iframe="https://en.cppreference.com/w/cpp/language/value_category" data-background-interactive -->

<div class="box" style="position: absolute; width: 45%; right: 0; background-color: rgba(0, 0, 0, 0.9); color: #fff; padding: 20px; font-size: 20px; text-align: left;">
    <h2> Kategorie wartości w C ++ </h2>
    <ul>
        <li> l-value </li>
        <li> prvalue </li>
        <li> xvalue </li>
        <li> glvalue = lvalue | xvalue </li>
        <li> rvalue = prvalue | xvalue </li>
    </ul>
    <p><a href="https://en.cppreference.com/w/cpp/language/value_category">Pełna lista na cppreference.com</a></p>
</div>
