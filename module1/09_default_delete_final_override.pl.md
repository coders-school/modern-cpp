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
    // operacje kopiowania zdefiniowane przez użytkownika zapobiegają
    // niejawnego powstawania domyślnych konstruktorów i operacji przenoszenia

    AwesomeClass() = default;
    AwesomeClass(AwesomeClass&&) = default;
    AwesomeClass& operator=(AwesomeClass&&) = default;
};
```

___

## słowo kluczowe `default`

* <!-- .element: class="fragment fade-in" --> deklaracja <code>default</code> wymusza na kompilatorze generowanie domyślnej niejawnej implementacji dla oznaczonych funkcji
* <!-- .element: class="fragment fade-in" --> 6 funkcji specjalnych można oznaczyć jako <code>default</code>:
  * domyślny konstruktor
  * konstruktor kopiujący
  * operator przypisania kopii
  * konstruktor przenoszący
  * operator przypisania ruchu
  * destruktor
* <!-- .element: class="fragment fade-in" --> Operacje zadeklarowane jako <code>default</code> są traktowane jako zadeklarowane przez użytkownika (nie zadeklarowane niejawnie)
* <!-- .element: class="fragment fade-in" --> Domyślna implementacja domyślnego c-tor wywołuje domyślny c-tor dla każdego składowego
* <!-- .element: class="fragment fade-in" --> Domyślna implementacja d-tor wywołuje d-tor dla każdego członka
* <!-- .element: class="fragment fade-in" --> Domyślną implementacją operacji kopiowania jest wywołanie operacji kopiowania dla każdego członka
* <!-- .element: class="fragment fade-in" --> Domyślną implementacją operacji przenoszenia jest wywołanie operacji przenoszenia dla każdego elementu członkowskiego

___

## `delete` słowo kluczowe

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

## `delete` słowo kluczowe

* <!-- .element: class="fragment fade-in" --> <code>delete</code> deklaracja usuwa zaznaczoną funkcję
* <!-- .element: class="fragment fade-in" --> Wywołanie usuniętej funkcji lub zajęcie jej adresu powoduje błąd kompilacji
* <!-- .element: class="fragment fade-in" --> Żaden kod nie jest generowany dla usuniętej funkcji
* <!-- .element: class="fragment fade-in" --> Usunięta funkcja jest traktowana jako zadeklarowana przez użytkownika
* <!-- .element: class="fragment fade-in" --> <code>delete</code> deklaracja może być używana do dowolnej funkcji, nie tylko do specjalnych funkcji składowych klasy
* <!-- .element: class="fragment fade-in" --> <code>delete</code> może służyć do uniknięcia niechcianej niejawnej konwersji argumentów funkcji

___

## `delete` słowo kluczowe

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

## Ćwiczenie

Oznacz konstruktory kopiujące jako domyślne.

Usunąć `getY()` metoda w `Square` i wszystkie domyślne (nieparametryczne) konstruktory kształtów.

___

## `final` słowo kluczowe

```cpp
struct A final {};

struct B : A {};    // compilation error
                    // cannot derive from class marked as final
```

`final` słowo kluczowe używane po deklaracji klasy / struktury blokuje dziedziczenie z tej klasy.
<!-- .element: class="fragment fade-in" -->

___

## `final` słowo kluczowe

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

`final` używane po blokach deklaracji funkcji wirtualnej przesłaniającej implementację w klasach pochodnych.
<!-- .element: class="fragment fade-in" -->

___

## `override` słowo kluczowe

<pre style = "position: bezwzględna; szerokość: 37%"><code class="cpp" data-trim data-line-numbers>
struct Base {
    virtual void a();
    virtual void b() const;
    virtual void c();
    void d();
};
</code></pre>

<pre class = "fragment" style = "position: bezwzględna; szerokość: 60%; po prawej: 0"><code class="cpp" data-trim data-line-numbers data-noescape>
struct WithoutOverride : Base {
    void a(); <span class="fragment">// overrides Base::a()</span>
    void b(); <span class="fragment">// doesn't override B::b() const</span>
    virtual void c(); <span class="fragment">// overrides B::c()</span>
    void d(); <span class="fragment">// doesn't override B::d()</span>
};
</code></pre>

<pre class = "fragment" style = "position: bezwzględna; width: 100%; top: 350px"><code class="cpp" data-trim data-line-numbers>
struct WithOverride : Base {
    void a() override; // OK - overrides Base::a()
    void b() override; // error - doesn't override B::b() const
    virtual void c() override; // OK - overrides B::c(char)
    void d() override; // error - B::d() is not virtual
};
</code></pre>

<p class = "fragment" style = "position: bezwzględna; width: 100%; top: 580px"><code>override</code> deklaracja wymusza na kompilatorze sprawdzenie, czy dana funkcja wirtualna jest zadeklarowana w taki sam sposób w klasie bazowej. </p>

___

## Ćwiczenie

znak `Circle` klasa jako `final`.

znak `getX()` w prostokącie jako `final`. Jaki jest problem?

Zaznacz wszystkie nadpisane metody wirtualne. Czy potrafisz dostrzec problem?
