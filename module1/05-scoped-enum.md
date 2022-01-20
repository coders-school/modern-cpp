<!-- .slide: data-background="#111111" -->
# Silne typy wyliczeniowe

## scoped `enum`

___

## Zwykłe `enum`

```cpp
enum Colors {
    RED = 10,
    ORANGE,
    GREEN
};

Colors a = RED;     // OK
int b = GREEN;      // OK

enum Fruits {
    ORANGE,
    BANANA
};

Colors c = ORANGE;  // 11 czy 0?
// Hopefully: error: ‘ORANGE’ conflicts with a previous declaration
```

___
<!-- .slide: style="font-size: 0.9em" -->
## `enum class`

```cpp
enum class Languages {
    ENGLISH,
    GERMAN,
    POLISH
};

Languages a = Languages::ENGLISH;
// Languages b = GERMAN;
// int c = Languages::ENGLISH;
int d = static_cast<int>(Languages::ENGLISH);   // only explicit cast allowed
```
<!-- .element: class="fragment fade-in" -->

**Motywacja**: Silniejsze i mniej podatne na błędy <code>enum</code>y.
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Wprowadzony w C++11
* <!-- .element: class="fragment fade-in" --> Ogranicza zakres zdefiniowanych stałych tylko do tych zdefiniowanych w klasie wyliczeniowej
* <!-- .element: class="fragment fade-in" --> Dostęp do wartości można uzyskać poprzedzając wartość nazwą <code>enum</code>a
* <!-- .element: class="fragment fade-in" --> Nie zezwala na niejawne konwersje, można zrobić jawną konwersją za pomocą <code>static_cast</code>
* <!-- .element: class="fragment fade-in" --> <code>enum class == enum struct</code>

___

## typ bazowy `enum`

```cpp
#include <iostream>
#include <limits>

enum Colors   { YELLOW = 10, ORANGE };
enum BigValue { VALUE = std::numeric_limits<long>::max() };
enum RgbColors : unsigned char {
    RED = 0x01,
    GREEN = 0x02,
    BLUE = 0x04,
    // BLACK = 0xFF + 1  // error: enumerator value 256 is outside
};                       // the range of underlying type ‘unsigned char’

int main() {
    std::cout << sizeof(Colors) << std::endl;    // 4 - sizeof(int)
    std::cout << sizeof(BigValue) << std::endl;  // 8 - sizeof(long)
    std::cout << sizeof(RgbColors) << std::endl; // 1 - sizeof(unsigned char)
    return 0;
}
```

[Pobaw się kodem na ideone.com](https://ideone.com/e.js/8sR1XK)

___

## rozmiar `enum`

* <!-- .element: class="fragment fade-in" --> Domyślny rozmiar <code>enum</code>a to <code>sizeof(int)</code>
* <!-- .element: class="fragment fade-in" --> typ bazowy <code>enum</code> jest rozszerzany automatycznie, jeśli wprowadzone wartości są większe od <code>int</code>
* <!-- .element: class="fragment fade-in" --> Aby zaoszczędzić trochę pamięci możemy zdefiniować typ bazowy za pomocą dziedziczenia
* <!-- .element: class="fragment fade-in" --> Kompilator nie pozwoli na zdefiniowanie wartości większej niż może pomieścić zdefiniowany typ bazowy
* <!-- .element: class="fragment fade-in" --> Dziedziczenie działa zarówno dla starych <code>enum</code>ów oraz dla <code>enum class</code>

___

## deklaracja zapowiadająca `enuma` (forward declaration)

W przypadku `enum`ów ze zdefiniowanym typem bazowym można podać samą deklarację, jeśli wartości nie muszą być znane.
<!-- .element: class="fragment fade-in" -->

Dzięki temu nie będzie potrzeby ponownej kompilacji pliku źródłowego, jeśli zostaną dodane nowe wartości do typu wyliczeniowego.
<!-- .element: class="fragment fade-in" -->

```cpp
enum Colors : unsigned int;
enum struct Languages : unsigned char;
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Napisz silny typ wyliczeniowy o nazwie `Color` i zdefiniuj w nim 3 wybrane kolory.

Dodaj dziedziczenie po `unsigned char`.

Dodaj nowe pole: `Color color` w klasie `Shape`, tak aby każdy kształt mógł mieć swój własny, zdefiniowany kolor.

Dodaj domyślną wartość koloru w klasie Shape.
