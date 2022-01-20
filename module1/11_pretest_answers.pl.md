<!-- .slide: data-background="#111111" -->

# Pre-test

## Odpowiedzi

___

## 1. Jaki jest typ zmiennej `v`?

```cpp
int i = 42;
const auto v = &i;
```

1. <!-- .element: class="fragment highlight-red" --> <code>const int</code>
1. <!-- .element: class="fragment highlight-red" --> <code>const int&</code>
1. <!-- .element: class="fragment highlight-green" --> <code>const int*</code>
1. <!-- .element: class="fragment highlight-red" --> inny

___

## 2. Które z poniższych inicjalizacji są poprawne w C++14?

```cpp
struct P { int a, b };
```

1. <!-- .element: class="fragment highlight-green" --> <code>int values[] = { 1, 2, 3, 4, 5 };</code>
1. <!-- .element: class="fragment highlight-green" --> <code>P v = { 1, 4 };</code>
1. <!-- .element: class="fragment highlight-green" --> <code>P v{1, 4};</code>
1. <!-- .element: class="fragment highlight-red" --> <code>P v(1, 4);</code>
1. <!-- .element: class="fragment highlight-green" --> <code>std::vector&lt;int> v = { 1, 2, 3, 4 };</code>
1. <!-- .element: class="fragment highlight-red" --> <code>std::vector&lt;int> v(1, 2, 3, 4);</code>
1. <!-- .element: class="fragment highlight-red" --> <code>int v[] = { 1, 3, 5, 6.6 };</code>

___

## 3. Które z poniższych elementów można zdefiniować jako usunięte (`= delete;`)?

1. <!-- .element: class="fragment highlight-green" --> domyślny konstruktor
1. <!-- .element: class="fragment highlight-green" --> konstruktor kopiujący
1. <!-- .element: class="fragment highlight-green" --> konstruktor przenoszący
1. <!-- .element: class="fragment highlight-green" --> kopiujący operator przypisania
1. <!-- .element: class="fragment highlight-green" --> przenoszący operator przypisania
1. <!-- .element: class="fragment highlight-green" --> destruktor
1. <!-- .element: class="fragment highlight-green" --> wolna funkcja
1. <!-- .element: class="fragment highlight-green" --> metoda klasy
1. <!-- .element: class="fragment highlight-red" --> pole klasy

___

## Praca domowa

Zajrzyj do pliku `README.md` z repozytorium coders-school/modern-cpp. Wykonaj wszystkie pozostałe zadania :)