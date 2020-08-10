## Move semantics

### Rationale

* Better optimization by avoiding redundant copies
* improved safety by keeping only one instance

___

## New syntax elements

* <!-- .element: class="fragment fade-in" --> <code>auto && value</code> - r-value reference
* <!-- .element: class="fragment fade-in" --> <code>Class(Class &&)</code> - move constructor
* <!-- .element: class="fragment fade-in" --> <code>Class& operator=(Class&&)</code> - move assignment operator
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> auxilary function
* <!-- .element: class="fragment fade-in" --> <code>std::forward()</code> auxilary function

___

## r-value and l-value

```cpp
struct A { int a, b; };

A foo() { return {1, 2}; }

A a;                    // l-value
A{5, 3};                // r-value
foo();                  // r-value
```

___

## r-value and l-value

* <!-- .element: class="fragment fade-in" --> l-value object has a name and address
* <!-- .element: class="fragment fade-in" --> l-value object is persistent, in the next line it can be accessed by name
* <!-- .element: class="fragment fade-in" --> r-value object does not have a name (usually) or address
* <!-- .element: class="fragment fade-in" --> r-value object is temporary, in the next line it will not be accessible

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

A const ca{20, 40};
A const&& rrc = ca;     // const r-value reference to const l-value, ERROR
```

___

## r-value or l-value?

<pre><code class="cpp" data-trim data-noescape>
str1 += str2                    <span class="fragment">// l-value</span>
str1 + str2                     <span class="fragment">// r-value</span>
[](int x){ return x * x; };     <span class="fragment">// r-value</span>
std::move(a);                   <span class="fragment">// r-value</span>
int && a = 4;                   <span class="fragment">// 4 is r-value</span>
</code></pre>

___

## r-value reference is... l-value?

### `int && a = 4;`

* <!-- .element: class="fragment fade-in" --> <code>4</code> is r-value
* <!-- .element: class="fragment fade-in" --> <code>a</code> is r-value reference
* <!-- .element: class="fragment fade-in" --> name <code>a</code> itself is an l-value (has an address, can be referenced lated)
* <!-- .element: class="fragment fade-in" --> but let's not think about it now 😉

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
