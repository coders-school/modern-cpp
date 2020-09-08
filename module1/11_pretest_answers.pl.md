<!-- .slide: data-background="#111111" -->

# Test wstępny

## Answers

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

## 2. Które z poniższych inicjalizacji są poprawne w C ++ 14?

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
1. <!-- .element: class="fragment highlight-green" --> przenieś konstruktora
1. <!-- .element: class="fragment highlight-green" --> operator przypisania kopii
1. <!-- .element: class="fragment highlight-green" --> operator przypisania przeniesienia
1. <!-- .element: class="fragment highlight-green" --> burzyciel
1. <!-- .element: class="fragment highlight-green" --> darmowa funkcja
1. <!-- .element: class="fragment highlight-green" --> metoda klasowa
1. <!-- .element: class="fragment highlight-red" --> obiekt elementu klasy

___

## Po teście

Link do post-testu zostanie wysłany do Ciebie w przyszłym tygodniu.

Lepiej zapomnieć o części treści i odświeżyć swoją wiedzę później.

Zwiększa retencję wiedzy :)

___

## Praca domowa

Zajrzyj do `README.md` plik z repozytorium modern_cpp. Możesz wykonać wszystkie zadania i zgłosić pull request, jeśli chcesz, żebym sprawdził twoją pracę domową.

___

## Sprzężenie zwrotne

* Co można poprawić w tym szkoleniu?
* Co było dla Ciebie najbardziej wartościowe?
* [Ocena szkolenia](https://forms.gle/qEZFvYKdgbxkyxYj7)
