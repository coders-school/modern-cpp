<!-- .slide: data-background="#111111" -->
# Nowe słowa kluczowe

## `default`, `delete`, `final`, `override`

___

## słowo kluczowe `default`

```cpp
class AwesomeClass {
public:
    AwesomeClass(const AwesomeClass&);
    AwesomeClass& operator=(const AwesomeClass&);
    // user defined copy operations prevents implicit generation
    // of default c-tor and move operations

    AwesomeClass() = default;
    AwesomeClass(AwesomeClass&&) = default;
    AwesomeClass& operator=(AwesomeClass&&) = default;
};
```

___
<!-- .slide: style="font-size: 0.9em" -->

## słowo kluczowe `default`

* <!-- .element: class="fragment fade-in" --> deklaracja <code>default</code> wymusza na kompilatorze generowanie domyślnej niejawnej implementacji dla oznaczonych funkcji
* <!-- .element: class="fragment fade-in" --> 6 funkcji specjalnych można oznaczyć jako <code>default</code>:
  * domyślny konstruktor
  * konstruktor kopiujący
  * kopiujący operator przypisania
  * konstruktor przenoszący
  * przenoszący operator przypisania
  * destruktor
* <!-- .element: class="fragment fade-in" --> Operacje zadeklarowane jako <code>default</code> są traktowane jako zadeklarowane przez użytkownika (nie zadeklarowane niejawnie)
* <!-- .element: class="fragment fade-in" --> Domyślna implementacja domyślnego konstruktora wywołuje domyślny konstruktor dla każdej składowej
* <!-- .element: class="fragment fade-in" --> Domyślna implementacja destruktora wywołuje destruktor dla każdej składowej
* <!-- .element: class="fragment fade-in" --> Domyślną implementacją operacji kopiowania jest wywołanie operacji kopiowania dla każdej składowej
* <!-- .element: class="fragment fade-in" --> Domyślną implementacją operacji przenoszenia jest wywołanie operacji przenoszenia dla każdej składowej

___

## słowo kluczowe `delete`

```cpp
class NoCopyable {  // NoCopyable idiom
public:
    NoCopyable() = default;
    NoCopyable(const NoCopyable&) = delete;
    NoCopyable& operator=(const NoCopyable&) = delete;
};

class NoMoveable {  // NoMoveable idiom
    NoMoveable(NoMoveable&&) = delete;
    NoMoveable& operator=(NoMoveable&&) = delete;
};
```

___

## słowo kluczowe `delete`

* <!-- .element: class="fragment fade-in" --> deklaracja <code>delete</code> usuwa zaznaczoną funkcję
* <!-- .element: class="fragment fade-in" --> Wywołanie usuniętej funkcji lub zajęcie jej adresu powoduje błąd kompilacji
* <!-- .element: class="fragment fade-in" --> Żaden kod nie jest generowany dla usuniętej funkcji
* <!-- .element: class="fragment fade-in" --> Usunięta funkcja jest traktowana jako zadeklarowana przez użytkownika
* <!-- .element: class="fragment fade-in" --> deklaracja <code>delete</code> może być używana do dowolnej funkcji, nie tylko do specjalnych funkcji składowych klasy
* <!-- .element: class="fragment fade-in" --> <code>delete</code> może służyć do uniknięcia niechcianej niejawnej konwersji argumentów funkcji

___

## słowo kluczowe `delete`

```cpp
void integral_only(int a) {
    // ...
}
void integral_only(double d) = delete;

integral_only(10);  // OK
short s = 3;
integral_only(s);   // OK - implicit conversion to int
integral_only(3.0); // error - use of deleted function
```

___

## Zadanie

Oznacz konstruktory kopiujące jako domyślne.

Usunąć metodę `getY()` w `Square` i wszystkie domyślne (nieparametryczne) konstruktory kształtów.

___

## słowo kluczowe `final`

```cpp
struct A final {};

struct B : A {};    // compilation error
                    // cannot derive from class marked as final
```

Słowo kluczowe `final` używane po deklaracji klasy/struktury blokuje dziedziczenie z tej klasy.
<!-- .element: class="fragment fade-in" -->

___

## słowo kluczowe `final`

```cpp
struct A {
    virtual void foo() const final {}
    void bar() const final {}   // compilation error, only virtual
                                // functions can be marked as final
};

struct B : A {
    void foo() const {}         // compilation error, cannot override
                                // function marked as final
};
```

`final` używane po deklaracji funkcji wirtualnej blokuje przesłaniającą implementację w klasach pochodnych.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.8em" -->

## słowo kluczowe `override`

```cpp
struct Base {
    virtual void a();
    virtual void b() const;
    virtual void c();
    void d();
};
```

```cpp
struct WithoutOverride : Base {
    void a();         // overrides Base::a()</span>
    void b();         // doesn't override B::b() const</span>
    virtual void c(); // overrides B::c()</span>
    void d();         // doesn't override B::d()</span>
};
```
<!-- .element: class="fragment fade-in" -->

```cpp
struct WithOverride : Base {
    void a() override;         // OK - overrides Base::a()
    void b() override;         // error - doesn't override B::b() const
    virtual void c() override; // OK - overrides B::c(char)
    void d() override;         // error - B::d() is not virtual
};
```
<!-- .element: class="fragment fade-in" -->

Deklaracja <code>override</code> wymusza na kompilatorze sprawdzenie, czy dana funkcja wirtualna jest zadeklarowana w taki sam sposób w klasie bazowej.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Oznacz klasę `Circle` jako `final`.

Oznacz `getX()` w prostokącie jako `final`. Jaki jest problem?

Zaznacz wszystkie nadpisane metody wirtualne. Czy potrafisz dostrzec problem?
