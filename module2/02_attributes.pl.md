<!-- .slide: data-background="#111111" -->
# Atrybuty

___
<!-- .slide: style="font-size: 0.9em" -->

## Atrybuty

Atrybuty zapewniają ujednoliconą standardową składnię dla zdefiniowanych w implementacji rozszerzeń językowych,
takie jak rozszerzenia językowe GNU i IBM `__attribute__((...))`, rozszerzenie Microsoft `declspec()` itp.

### Atrybuty standardowe
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>[[noreturn]]</code> - funkcja nigdy nie wraca, jak <code>std::terminate</code>. Jeśli wróci, mamy UB
* <!-- .element: class="fragment fade-in" --> <code>[[deprecated]]</code> (C++14) - funkcja jest przestarzała
* <!-- .element: class="fragment fade-in" --> <code>[[deprecated("reason")]]</code> (C++14) - jak wyżej, ale kompilator poda przyczynę
* <!-- .element: class="fragment fade-in" --> <code>[[fallthrough]]</code> (C++17) - w <code>switch</code> oświadczenie, wskazujące, że przejście przez kolejny przypadek (case) jest zamierzone
* <!-- .element: class="fragment fade-in" --> <code>[[nodiscard]]</code> (C++17) - nie można ignorować wartości zwracanej z funkcji
* <!-- .element: class="fragment fade-in" --> <code>[[maybe_unused]]</code> (C++17) - pomiń ostrzeżenie kompilatora o nieużywanej klasie, typedef, zmiennej, funkcji itp.

___

## Atrybut `[[noreturn]]`

```c++
[[noreturn]] void f() {
    throw "error";
    // OK
}

[[noreturn]] void q(int i) {
    if (i > 0) {
        throw "positive";
    }
    // niezdefiniowane zachowanie, jeśli funkcja wywołana z argumentem <=0
}
```

___

## Atrybut `[[fallthrough]]`

```c++
void f(int n){
    void g(), h(), i();
    switch(n) {
    case 1:
    case 2:
        g();
        [[fallthrough]];
    case 3: // brak ostrzeżenia przy przejściu do następnego przypadku
        h();
    case 4: // kompilator może ostrzegać przed przejściem
        i();
        [[fallthrough]]; // źle, brak przypadku za atrybutem
    }
}
```

___

## Atrybut `[[nodiscard]]`

```c++
struct [[nodiscard]] error_info {};
error_info process(Data*);

// ...

void passMessage() {
    auto data = getData();
    process(data);  // ostrzeżenie kompilatora, ignorowanie zwracanej wartości
}
```

___

## Atrybut `[[maybe_unused]]`

```c++
[[maybe_unused]] void f([[maybe_unused]] bool thing1,
                        [[maybe_unused]] bool thing2)
{
  [[maybe_unused]] bool b = thing1 && thing2;
  assert (b); // assert zostaje skompilowane, podczas gdy b nieużyte
              // brak ostrzeżenia, bo mamy zadeklarowany [[maybe_unused]]
} // parametry thing1 i thing2 nie są użyte, brak ostrzeżenia
```

___

## Atrybut `[[deprecated]]`

Atrybuty dla przestrzeni nazw i typów wyliczeniowych są dostępne w języku C++17.

```c++
[[deprecated("Please use f2 instead")]] int f1();

enum E {
    foobar = 0,
    boobat [[deprecated]] = foobar
};
E e = foobat; // ostrzeżenie kompilatora

namespace [[deprecated]] old_stuff {
    void legacy();
}
old_stuff::legacy(); // ostrzeżenie kompilatora
```

___

## Zadanie

Dodaj nową metodę `double getPi()` do klasy `Circle`, która zwraca liczbę PI. Oznacz ją jako przestarzałą.
