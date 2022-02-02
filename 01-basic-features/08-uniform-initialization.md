<!-- .slide: data-background="#111111" -->
# Jednolita inicjalizacja

___

## Inicjalizacja w C++98/03

<pre><code class="cpp" data-trim data-line-numbers data-noescape>
int a;          <span class="fragment">// undefined value</span>
int b(5);       <span class="fragment">// direct initialization, b = 5</span>
int c = 10;     <span class="fragment">// copy initialization, c = 10</span>
int d = int();  <span class="fragment">// default initialization, d = 0</span>
int e();        <span class="fragment">// function declaration - "most vexing parse"</span>

int values[] = { 1, 2, 3, 4 };  <span class="fragment">// brace initialization of aggregate</span>
int array[] = { 1, 2, 3.5 };    <span class="fragment">// C++98 - ok, implicit type narrowing</span>

struct P { int a, b; };
P p = { 20, 40 };                  <span class="fragment">// brace initialization of POD</span>

std::complex&lt;double> c(4.0, 2.0);  <span class="fragment">// initialization of classes</span>

std::vector&lt;std::string> names;    <span class="fragment">// no initialization for list of values</span>
names.push_back("John");
names.push_back("Jane");
</code></pre>

___

## inicjalizacja w C++11 z użyciem `{}`

<pre><code class="cpp" data-trim data-line-numbers data-noescape>
int a;          <span class="fragment">// still undefined value</span>
int b{5};       <span class="fragment">// brace initialization, b = 5</span>
int c{};        <span class="fragment">// brace initialization, c = 0</span>

int values[] = { 1, 2, 3, 4 };  <span class="fragment">// brace initialization of aggregate</span>
int array[] = { 1, 2, 3.5 };    <span class="fragment">// C++11: error - implicit type narrowing</span>

struct P { int a, b; };
P p = { 20, 40 };               <span class="fragment">// brace initialization of POD</span>

std::complex&lt;double> c{4.0, 2.0};   <span class="fragment">// brace initialization calls adequate c-tor</span>

std::vector&lt;std::string> names = { "John", "Jane" };  <span class="fragment">// brace initialization of vector</span>
</code></pre>

**Motywacja**: wyeliminowanie problematycznych przypadków inicjalizacji z C++98, inicjalizacja kontenerów STL, jeden uniwersalny sposób inicjalizacji.
<!-- .element: class="fragment fade-in" -->

___

## Inicjalizacja zmiennych niestatycznych w klasie

```cpp
struct Foo
{
    Foo() {}
    Foo(std::string a) : a_(a) {}
    void print() { std::cout << a_ << std::endl; }

private:
   std::string a_ = "Foo";              // C++98: error, C++11: OK
   static const unsigned VALUE = 20u;   // C++98: OK, C++11: OK
};

Foo().print();          // Foo
Foo("Bar").print();     // Bar
```

___

## `std::initializer_list<T>`

```cpp
auto values = {1, 2, 3, 4, 5};   // values is std::initializer_list<int>
std::vector<int> v = {1, 2, -3}; // creates a vector from
                                 // std::initializer_list<int>
```

* <!-- .element: class="fragment fade-in" --> Zdefiniowany w nagłówku <code>initializer_list</code>
* <!-- .element: class="fragment fade-in" --> Elementy są przechowywane w tablicy
* <!-- .element: class="fragment fade-in" --> Elementy są niezmienne (immutable)
* <!-- .element: class="fragment fade-in" --> Elementy muszą być kopiowalne
* <!-- .element: class="fragment fade-in" --> Ma ograniczony interfejs, ma dostęp przez iteratory - <code>begin()</code>, <code>end()</code>, <code>size()</code>
* <!-- .element: class="fragment fade-in" --> Powinien być przekazywany do funkcji przez wartość

___

## Priorytety konstruktorów

<pre><code class="cpp" data-trim data-line-numbers data-noescape>
template&lt;class Type>
class Bar {
    std::vector&lt;Type> values_;
public:
    Bar(std::initializer_list&lt;Type> values) : values_(values) {}
    Bar(Type a, Type b) : values_{a, b} {}
};

<span class="fragment">Bar&lt;int> c = {1, 2, 5, 51};</span>   <span class="fragment">// calls std::initializer_list c-tor</span>
<span class="fragment">Bar&lt;int> d{1, 2, 5, 51};</span>      <span class="fragment">// calls std::initializer_list c-tor</span>
<span class="fragment">Bar&lt;int> e = {1, 2};</span>          <span class="fragment">// calls std::initializer_list c-tor</span>
<span class="fragment">Bar&lt;int> f{1, 2};</span>             <span class="fragment">// calls std::initializer_list c-tor</span>
<span class="fragment">Bar&lt;int> g(1, 2);</span>             <span class="fragment">// calls Bar(Type a, Type b) c-tor</span>
<span class="fragment">Bar&lt;int> h = {};</span>              <span class="fragment">// calls std::initializer_list c-tor</span>
                              <span class="fragment">// or default c-tor if exists</span>
<span class="fragment">Bar&lt;std::unique_ptr&lt;int>> c = {new int{1}, new int{2}};</span>
<span class="fragment">// error - std::unique_ptr is non-copyable</span>
</code></pre>

Konstruktor z <code>std::initializer_list</code> ma większy priorytet, nawet jeśli inne konstruktory pasują lepiej.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Zastosuj `initializer_list`, aby zainicjować kolekcję `shapes`.

Dodaj nowy konstruktor do Shape - `Shape(Color c)`. Co się dzieje?

Użyj dziedziczenia konstruktora, aby umożliwić inicjalizację wszystkich kształtów, podając tylko `Color` jako parametr.

Utwórz kilka kształtów, podając tylko parametr `Color`.

Dodaj inicjalizację pola w klasie dla wszystkich kształtów, aby bezpiecznie używać odziedziczonego konstruktora.
