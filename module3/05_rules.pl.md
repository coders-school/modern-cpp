## Zasada 3

Jeśli zdefiniujesz co najmniej jeden:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> destruktor
* <!-- .element: class="fragment fade-in" --> konstruktor kopiujący
* <!-- .element: class="fragment fade-in" --> kopiujący operator przypisania

oznacza to, że ręcznie zarządzasz zasobami i <span class="fragment highlight-red">powinieneś wdrożyć je wszystkie</span>.
<!-- .element: class="fragment fade-in" -->

Zapewni to poprawność w każdym kontekście.
<!-- .element: class="fragment fade-in" -->

___

## Zasada 5

Zasada 5 = Zasada 3 + optymalizacje

* destruktor
* konstruktor kopiujący
* kopiujący operator przypisania
* <!-- .element: class="fragment highlight-green" --> konstruktor przenoszący
* <!-- .element: class="fragment highlight-green" --> przenoszący operator przypisania

Od C++11 używaj zasady 5.
<!-- .element: class="fragment fade-in" -->

___

## Zasada 0

Nie wdrażaj żadnej z funkcji zasady 5 😎
<!-- .element: class="fragment highlight-green" -->

Jeśli używasz programów obsługi RAII (takich jak inteligentne wskaźniki), wszystkie operacje kopiowania i przenoszenia zostaną wygenerowane (lub usunięte) niejawnie.
<!-- .element: class="fragment fade-in" -->

Na przykład kiedy masz unique_ptr jako składową swojej klasy, operacje kopiowania Twojej klasy zostaną automatycznie zablokowane, ale operacje przenoszenia będą obsługiwane.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Cel: naucz się refaktoryzować kod, aby używać RAII i reguły 0

Napisz klasę szablonu, która zawiera wskaźnik

* <!-- .element: class="fragment fade-in" --> użyj zwykłego wskaźnika do zarządzania zasobami typu szablonu
* <!-- .element: class="fragment fade-in" --> zaimplementuj konstruktor do uzyskania zasobów
* <!-- .element: class="fragment fade-in" --> zaimplementuj zasadę 3
* <!-- .element: class="fragment fade-in" --> zaimplementuj zasadę 5
* <!-- .element: class="fragment fade-in" --> zaimplementuj zasadę 0
  * użyj odpowiedniego inteligentnego wskaźnika zamiast zwykłego wskaźnika
  <!-- .element: class="fragment fade-in" -->
