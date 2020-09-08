<!-- .slide: data-background="#111111" -->
# Jednolita inicjalizacja

___

## Inicjalizacja w C++98/03

<pre><code class="cpp" data-trim data-line-numbers data-noescape>
int a;          <span class="fragment">// niezdefiniowana wartość</span>
int b(5);       <span class="fragment">// bezpośrednia inicjalizacja, b = 5</span>
int c = 10;     <span class="fragment">// inicjalizacja przez kopię, c = 10</span>
int d = int();  <span class="fragment">// domyślna inicjalizacja, d = 0</span>
int e();        <span class="fragment">// deklaracja funkcji - "most vexing parse"</span>
<!-- nie mam pojęcia jak to przetłumaczyć :x (można dosłownie, ale chyba lepiej zostawić oryginał w takim przypadku) -->

int values[] = { 1, 2, 3, 4 };  <span class="fragment">// inicjalizacja zbiorcza agregatów</span>
int array[] = { 1, 2, 3.5 };    <span class="fragment">// C++98 - ok, niejawna konwersja typu</span>

struct P { int a, b; };
P p = { 20, 40 };                  <span class="fragment">// inicjalizacja zbiorcza POD</span>

std::complex&lt;double> c(4.0, 2.0);  <span class="fragment">// inicjalizacja klasy</span>

std::vector&lt;std::string> names;    <span class="fragment">// brak inicjalizacji dla listy wartości</span>
names.push_back("John");
names.push_back("Jane");
</code></pre>

___

## C++11 inicjalizacja z {}

<pre><code class="cpp" data-trim data-line-numbers data-noescape>
int a;          <span class="fragment">// wciąż niezdefiniowana wartość</span>
int b{5};       <span class="fragment">// inicjalizacja zbiorcza, b = 5</span>
int c{};        <span class="fragment">// inicjalizacja zbiorcza, c = 0</span>

int values[] = { 1, 2, 3, 4 };  <span class="fragment">// inicjalizacja zbiorcza agregatów</span>
int array[] = { 1, 2, 3.5 };    <span class="fragment">// C++11: error - niejawna konwersja typu</span>

struct P { int a, b; };
P p = { 20, 40 };               <span class="fragment">// inicjalizacja zbiorcza POD</span>

std::complex&lt;double> c{4.0, 2.0};   <span class="fragment">// inicjalizacja zbiorcza wywołuje odpowiedni konstruktor</span>

std::vector&lt;std::string> names = { "John", "Jane" };  <span class="fragment">// inicjalizacja zbiorcza wektora</span>
</code></pre>

**Uzasadnienie**: eliminacja problematycznych przypadków inicjalizacji z C++98, inicjalizacja kontenerów STL, ma jeden uniwersalny sposób inicjalizacji.
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
auto values = {1, 2, 3, 4, 5};   // values jest typu std::initializer_list<int>
std::vector<int> v = {1, 2, -3}; // tworzy wektor z typu
                                 // std::initializer_list<int>
```

* <!-- .element: class="fragment fade-in" --> Zdefiniowany w nagłówku <code>initializer_list</code>
* <!-- .element: class="fragment fade-in" --> Elementy są przechowywane w tablicy
* <!-- .element: class="fragment fade-in" --> Elementy są niezmienne
* <!-- .element: class="fragment fade-in" --> Elementy muszą być kopiowalne
* <!-- .element: class="fragment fade-in" --> Mają ograniczony interfejs i dostęp przez iteratory - <code>begin()</code>, <code>end()</code>, <code>size()</code>
* <!-- .element: class="fragment fade-in" --> Powinien być przekazywany do funkcji przez wartość

___

## Priorytet konstruktora

<pre><code class="cpp" data-trim data-line-numbers data-noescape>
template&lt;class Type>
class Bar {
    std::vector&lt;Type> values_;
public:
    Bar(std::initializer_list&lt;Type> values) : values_(values) {}
    Bar(Type a, Type b) : values_{a, b} {}
};

<span class="fragment">Bar&lt;int> c = {1, 2, 5, 51};</span>   <span class="fragment">// wywołuje konstruktor std::initializer_list</span>
<span class="fragment">Bar&lt;int> d{1, 2, 5, 51};</span>      <span class="fragment">// wywołuje konstruktor std::initializer_list</span>
<span class="fragment">Bar&lt;int> e = {1, 2};</span>          <span class="fragment">// wywołuje konstruktor std::initializer_list</span>
<span class="fragment">Bar&lt;int> f{1, 2};</span>             <span class="fragment">// wywołuje konstruktor std::initializer_list</span>
<span class="fragment">Bar&lt;int> g(1, 2);</span>             <span class="fragment">// wywołuje konstruktor Bar(Type a, Type b)</span>
<span class="fragment">Bar&lt;int> h = {};</span>              <span class="fragment">// wywołuje konstruktor std::initializer_list</span>
                              <span class="fragment">// lub domyślny konstruktor jeśli istnieje</span>
<span class="fragment">Bar&lt;std::unique_ptr<int>> c = {new int{1}, new int{2}};</span>
<span class="fragment">// error - std::unique_ptr is non-copyable</span>
</code></pre>

Konstruktor z <code>std::initializer_list</code> ma większy priorytet, nawet jeśli inne elementy są zgodne.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Zastosuj `initializer_list`, aby zainicjować kolekcję.

Dodaj nowy konstruktor do Shape - `Shape(Color c)`. Co się dzieje?

Użyj dziedziczenia konstruktora, aby umożliwić inicjalizację wszystkich kształtów, podając tylko `Color` jako parametr.

Utwórz kilka kształtów, podając tylko parametr `Color`.

Dodaj inicjalizację pola w klasie dla wszystkich kształtów, aby bezpiecznie używać konstruktora dziedziczonego.
