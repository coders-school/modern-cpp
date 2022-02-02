<!-- .slide: data-background="#111111" -->
# New keywords

## `default`, `delete`, `final`, `override`

___

## `default` keyword

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

## `default` keyword

* <!-- .element: class="fragment fade-in" --> <code>default</code> declaration enforces a compiler to generate default implicit implementation for marked functions
* <!-- .element: class="fragment fade-in" --> 7 special functions can be marked as <code>default</code>:
  * default c-tor
  * copy c-tor
  * copy assignment operator
  * move c-tor
  * move assignment operator
  * destructor
* <!-- .element: class="fragment fade-in" --> Operations declared as <code>default</code> are treated as user-declared (not implicitly-declared)
* <!-- .element: class="fragment fade-in" --> The default implementation of default c-tor is calling default c-tor for every member
* <!-- .element: class="fragment fade-in" --> The default implementation of d-tor is calling d-tor for every member
* <!-- .element: class="fragment fade-in" --> The default implementation of copy operations is calling copy operation for every member
* <!-- .element: class="fragment fade-in" --> The default implementation of move operations is calling move operation for every member

___

## `delete` keyword

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

## `delete` keyword

* <!-- .element: class="fragment fade-in" --> <code>delete</code> declaration removes marked function
* <!-- .element: class="fragment fade-in" --> Calling a deleted function or taking its address causes a compilation error
* <!-- .element: class="fragment fade-in" --> No code is generated for deleted function
* <!-- .element: class="fragment fade-in" --> Deleted function are treated as user-declared
* <!-- .element: class="fragment fade-in" --> <code>delete</code> declaration can be used on any function, not only special class member functions
* <!-- .element: class="fragment fade-in" --> <code>delete</code> can be used to avoid unwanted implicit conversion of function arguments

___

## `delete` keyword

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

## Exercise

Mark copy constructors as default.

Delete `getY()` method in `Square` and all default (non-parametric) constructors of shapes.

___

## `final` keyword

```cpp
struct A final {};

struct B : A {};    // compilation error
                    // cannot derive from class marked as final
```

`final` keyword used after a class/struct declaration blocks inheritance from this class.
<!-- .element: class="fragment fade-in" -->

___

## `final` keyword

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

`final` used after a virtual function declaration blocks overriding the implementation in derived classes.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.8em" -->

## `override` keyword

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
    void a();         // overrides Base::a()
    void b();         // doesn't override Base::b() const
    virtual void c(); // overrides Base::c()
    void d();         // doesn't override Base::d()
};
```
<!-- .element: class="fragment fade-in" -->

```cpp
struct WithOverride : Base {
    void a() override;         // OK - overrides Base::a()
    void b() override;         // error - doesn't override Base::b() const
    virtual void c() override; // OK - overrides Base::c()
    void d() override;         // error - Base::d() is not virtual
};
```
<!-- .element: class="fragment fade-in" -->

<code>override</code> declaration enforces a compiler to check, if given virtual function is declared in the same way in a base class.
<!-- .element: class="fragment fade-in" -->

___

## Exercise

Mark `Circle` class as `final`.

Mark `getX()` in Rectangle as `final`. What is the problem?

Mark all overridden virtual methods. Can you spot the problem?
