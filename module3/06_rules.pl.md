## Zasada 3

Jeśli zdefiniujesz co najmniej jeden z:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> burzyciel
* <!-- .element: class="fragment fade-in" --> konstruktor kopiujący
* <!-- .element: class="fragment fade-in" --> operator przypisania kopii

oznacza to, że ręcznie zarządzasz zasobami i <span class="fragment highlight-red">powinieneś wdrożyć je wszystkie</span>.
<!-- .element: class="fragment fade-in" -->

Zapewni poprawność w każdym kontekście.
<!-- .element: class="fragment fade-in" -->

___

## Zasada 5

Reguła 5 = Reguła 3 + optymalizacje

* destructor
* konstruktor kopiujący
* operator przypisania kopii
* <!-- .element: class="fragment highlight-green" --> przenieś konstruktora
* <!-- .element: class="fragment highlight-green" --> operator przypisania przeniesienia

Od C ++ 11 użyj reguły 5.
<!-- .element: class="fragment fade-in" -->

___

## Reguła 0

Nie wdrażaj żadnej z funkcji reguły 5 😎
<!-- .element: class="fragment highlight-green" -->

Jeśli używasz programów obsługi RAII (takich jak inteligentne wskaźniki), wszystkie operacje kopiowania i przenoszenia zostaną wygenerowane (lub usunięte) niejawnie.
<!-- .element: class="fragment fade-in" -->

Na przykład. kiedy masz unique_ptr jako członka swojej klasy, operacje kopiowania Twojej klasy zostaną automatycznie zablokowane, ale operacje przenoszenia będą obsługiwane.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Cel: naucz się refaktoryzować kod, aby używać RAII i reguły 0

Napisz klasę szablonu, która zawiera wskaźnik

* <!-- .element: class="fragment fade-in" --> użyj surowego wskaźnika do zarządzania zasobami typu szablonu
* <!-- .element: class="fragment fade-in" --> implementuj konstruktora, aby uzyskać zasób
* <!-- .element: class="fragment fade-in" --> wdrożyć zasadę 3
* <!-- .element: class="fragment fade-in" --> wdrożyć zasadę 5
* <!-- .element: class="fragment fade-in" --> wdrożyć regułę 0
  * użyj odpowiedniego inteligentnego wskaźnika zamiast surowego wskaźnika
  <!-- .element: class="fragment fade-in" -->
