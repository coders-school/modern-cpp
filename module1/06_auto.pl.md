<!-- .slide: data-background="#111111" -->
# Automatyczna dedukcja typu

___

## słowo kluczowe `auto`

```cpp
auto a;         // error: declaration of ‘auto a’ has no initializer
auto i = 42;    // i jest typu int
auto u = 42u;   // u jest typu unsigned
auto d = 42.0;  // d jest typu double
auto f = 42.0f; // f jest typu float

double f();
auto r1 = f();  // r1 jest typu double

std::set<std::string> collection;
auto it = collection.begin(); // it jest typu std::set<std::string>::iterator
```

**Uzasadnienie**: Nieważne (ale silnie zdefiniowane) typy, mniej pisania, mniej refaktoryzacji.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Kompilator może automatycznie wywnioskować typ zmiennej podczas inicjalizacji
* <!-- .element: class="fragment fade-in" --> Dedukcja jest dokonywana na podstawie literału, innej zmiennej lub zwracanego typu funkcji
* <!-- .element: class="fragment fade-in" --> Obowiązują takie same zasady, jak w przypadku dedukcji szablonów

___

## Modyfikatory zmiennych

```cpp
int func() { return 10; }

int main() {
    const auto& v1 = func(); // v1 jest typu const int&
    const auto v2 = func();  // v2 jest typu const int
    // auto& v3 = func();    // error: cannot bind non-const lvalue reference
                             // of type ‘int&’ to an rvalue of type ‘int’
    auto v4 = func();        // v4 jest typu int
    return 0;
}
```

___
<!-- .slide: style="font-size: 0.9em" -->

### Reguły dedukcji dla referencji

```cpp
const vector<int> values;
auto v1 = values;   // v1 : vector<int>
auto& v2 = values;  // v2 : const vector<int>&

volatile long clock = 0L;
auto c1 = clock;    // c1 : long
auto& c2 = clock;   // c2 : volatile long&

Gadget items[10];
auto g1 = items;    // g1 : Gadget*
auto& g2 = items;   // g2 : Gadget(&)[10] - referencja do
                    // 10. elementu tablicy typu Gadget

int func(double) { return 10; }
auto f1 = func;     // f1 : int (*)(double)
auto& f2 = func ;   // f2: int (&)(double)
```

* <!-- .element: class="fragment fade-in" --> Referencja oznacza ten sam obiekt o takich samych właściwościach
* <!-- .element: class="fragment fade-in" --> Referencja zachowuje kwalifikatory cv (cv-qualifiers: <code>const</code>, <code>volatile</code>)
* <!-- .element: class="fragment fade-in" --> Kopia porzuca kwalifikatory cv
* <!-- .element: class="fragment fade-in" --> Kopia tablicy zamienia się na wskaźnik

___

### Deklaracja funkcji ze strzałką

```cpp
int sum(int a, int b);
auto sum(int a, int b) -> int;


auto isEven = [](int a) -> bool {
    return a % 2;
}
```

Wprowadzono, aby umożliwić definicję typu zwracanego z funkcji lambda.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

### Dedukcji typu zwracanego przez funkcję

```cpp
auto multiply(int x, int y) {
    return x * y;
}

auto get_name(int id) {
    if (id == 1)
        return std::string("Gadget");
    else if (id == 2)
        return std::string("SuperGadget");
    return string("Unknown");
}

auto factorial(int n) {
    if (n == 1)
        return 1;
    return factorial(n - 1) * n;
}
```

* <!-- .element: class="fragment fade-in" --> Wprowadzony w C++14
* <!-- .element: class="fragment fade-in" --> Mechanizm dedukcji jest taki sam, jak w przypadku dedukcji typów zmiennych
* <!-- .element: class="fragment fade-in" --> Wszystkie instrukcje <code>return</code> muszą zwracać ten sam typ
* <!-- .element: class="fragment fade-in" --> Rekursja jest dozwolona tylko wtedy, gdy rekurencyjne wywołanie funkcji nie jest w pierwszej instrukcji <code>return</code>

___

## zakresowa pętla for

```cpp
std::vector<int> v = {0, 1, 2, 3, 4, 5};

for (const auto & element : v) {
    std::cout << element << ' ';
}
std::cout << '\n';
```

___

### Wygenerowany kod dla zakresu na podstawie pętli for

```cpp
{
    auto && __range = range_expression ;
    auto __begin = begin_expr ;
    auto __end = end_expr ;
    for ( ; __begin != __end; ++__begin) {
        range_declaration = *__begin;
        loop_statement
    }
}
```

___
<!-- .slide: data-background="#cf802a" -->

## Zadanie

Umieść auto tam, gdzie uważasz, że jest dobre.

Tam, gdzie to możliwe, używaj pętli zakresowych.

### Zabawmy się :)
<!-- .element: class="fragment fade-in" -->

Połącz się z moim VSC i jednocześnie edytuj mój program.
<!-- .element: class="fragment fade-in" -->
