## Rule of 3

Jeśli zdefiniujesz przynajmniej jedną z poniższych funkcji:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> destruktor
* <!-- .element: class="fragment fade-in" --> konstruktor kopiujący
* <!-- .element: class="fragment fade-in" --> kopiujący operator przypisania

to znaczy, że ręcznie zarządzasz zasobami i <span class="fragment highlight-red">należy zaimplementować je wszystkie</span>.
<!-- .element: class="fragment fade-in" -->

To zapewni poprawność w każdym kontekście użycia.
<!-- .element: class="fragment fade-in" -->

___

## Rule of 5

Rule of 5 = Rule of 3 + optymalizacje

* destruktor
* konstruktor kopiujący
* kopiujący operator przypisania
* <!-- .element: class="fragment highlight-green" --> konstruktor przenoszący
* <!-- .element: class="fragment highlight-green" --> przenoszący operator przypisania

Od C++11 zawsze stosujemy Rule of 5 zamiast Rule of 3.
<!-- .element: class="fragment fade-in" -->

___

## Rule of 0

Nie implementuj żadnej z funkcji z Rule of 5 😎
<!-- .element: class="fragment highlight-green" -->

Jeśli używasz klas RAII (jak smart pointery), to wszystkie operacje kopiowania i przenoszenia zostaną wygenerowane automatycznie (lub usunięte) przez kompilator .
<!-- .element: class="fragment fade-in" -->

Na przykład, jeśli trzymasz w swojej klasie `unique_ptr`, to kopiowanie obiektów twojej klasy zostanie automatycznie zablokowane, ale dostępne będzie ich przenoszenie.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Cel: refaktoryzacja kodu w celu użycia RAII i Rule of 0

Napisz klasę szablonową, która trzyma wskaźnik.

* <!-- .element: class="fragment fade-in" --> użyj zwykłego wskaźnika, aby zarządzać pamięcią do typu szablonowego
* <!-- .element: class="fragment fade-in" --> zaimplementuj konstruktor, w którym pozyskasz zasób
* <!-- .element: class="fragment fade-in" --> zaimplementuj Rule of 3
* <!-- .element: class="fragment fade-in" --> zaimplementuj Rule of 5
* <!-- .element: class="fragment fade-in" --> zaimplementuj Rule of 0
  * użyj odpowiedniego smart pointera zamiast zwykłego wskaźnika
  <!-- .element: class="fragment fade-in" -->
