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
    // the behavior is undefined if called with argument <=0
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
    case 3: // no warning on fallthrough
        h();
    case 4: // compiler may warn on fallthrough
        i();
        [[fallthrough]]; // illformed, not before a case label
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
    process(data);  // compiler warning, discarding error_info
}
```

___

## Atrybut `[[maybe_unused]]`

```c++
[[maybe_unused]] void f([[maybe_unused]] bool thing1,
                        [[maybe_unused]] bool thing2)
{
  [[maybe_unused]] bool b = thing1 && thing2;
  assert (b); // in release mode, assert is compiled out, and b is unused
              // no warning because it is declared [[maybe_unused]]
} // parameters thing1 and thing2 are not used, no warning
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
E e = foobat; // Emits warning

namespace [[deprecated]] old_stuff {
    void legacy();
}
old_stuff::legacy(); //Emits warning
```

___

## Zadanie

Dodaj nową metodę `double getPi()` do klasy `Circle`, która zwraca liczbę PI. Oznacz ją jako przestarzałą.
