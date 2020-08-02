<!-- .slide: data-background="#111111" -->

# Move semantics in C++

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

### Łukasz Ziobroń
### Kamil Szatkowski

---

## Let's get to know each other

1. <!-- .element: class="fragment fade-in" --> Your name and programming experience
2. <!-- .element: class="fragment fade-in" --> What you don't like in C++?
3. <!-- .element: class="fragment fade-in" --> Your hobbies

---

<!-- .slide: data-background="../img/lukasz.jpg" -->

<h2 style="text-shadow: 2px 2px black;">Łukasz Ziobroń</h2>
<div class="box fragment" style="width: 45%; left: 0; top: 100px;">
    <h3>Not only a programming XP</h3>
    <ul>
        <li>Entrepreneur, Trainer, Frontend dev @ Coders School</li>
        <li>C++ and Python dev @ Nokia & Credit Suisse</li>
        <li>Team leader & Trainer @ Nokia</li>
        <li>Scrum Master @ Nokia & Credit Suisse</li>
        <li>Code Reviewer @ Nokia</li>
        <li>Webdeveloper (HTML, PHP, CSS) @ StarCraft Area</li>
    </ul>
</div>
    
<div class="box fragment" style="width: 45%; right: 0; top: 100px;">
    <h3>Training experience</h3>
    <ul>
        <li>C++ trainings @ Coders School</li>
        <li>Practial Aspects Of Software Engineering @ PWr & UWr</li>
        <li>Nokia Academy @ Nokia</li>
        <li>Internal corporate trainings</li>
    </ul>
</div>
    
<div class="box fragment" style="width: 45%; left: 0; top: 400px;">
    <h3>Public speaking experience</h3>
    <ul>
        <li>code::dive conference</li>
        <li>code::dive community</li>
        <li>Academic Championships in Team Programming</li>
    </ul>
</div>

<div class="box fragment" style="width: 45%; right: 0; top: 400px;">
    <h3>Hobbies</h3>
    <ul>
        <li>StarCraft Brood War & StarCraft II</li>
        <li>Motorcycles</li>
        <li>Photography</li>
        <li>Archery</li>
        <li>Andragogy</li>
    </ul>
</div>

---

## Agenda

* <!-- .element: class="fragment fade-in" --> intro & testing setup (30”)
* <!-- .element: class="fragment fade-in" --> r-values and l-values (20”)
* <!-- .element: class="fragment fade-in" --> move constructor and move assignment operator (20”) 
* <!-- .element: class="fragment fade-in" --> implementation of move semantics - remote coding dojo (1h)
* <!-- .element: class="fragment fade-in" --> rule of 0, 3, 5 (15”) 
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> (20”) 
* <!-- .element: class="fragment fade-in" --> forwarding reference (20”)
* <!-- .element: class="fragment fade-in" --> reference collapsing (20”)
* <!-- .element: class="fragment fade-in" --> <code>std::forward()</code> and perfect forwarding (45”) 
* <!-- .element: class="fragment fade-in" --> copy elision, RVO (return value optimisation) (30”)
* <!-- .element: class="fragment fade-in" --> recap (20”)

---

## Contract

* <!-- .element: class="fragment fade-in" --> 🎰 Vegas rule
* <!-- .element: class="fragment fade-in" --> 🗣 Be active - ask a lot
* <!-- .element: class="fragment fade-in" --> 🍽 1 lunch break (about 12:30)
* <!-- .element: class="fragment fade-in" --> ☕️ 2 coffee breaks, additional breaks on demand
* <!-- .element: class="fragment fade-in" --> ⌚️ Be on time after breaks

---

## Pre-test

### Question 1/2

Take a pen ✏

```cpp
template <typename T>
void foo(T && a) {std::cout << "OK\n"; }

int a = 5;
```
<!-- .element: class="fragment fade-in" -->

We have only above template function defined.
What will happen in each case? Which example will compile and display "OK"?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>foo(4);</code>
* <!-- .element: class="fragment fade-in" --> <code>foo(a);</code>
* <!-- .element: class="fragment fade-in" --> <code>foo(std::move(a));</code>

Tell me when you are ready
<!-- .element: class="fragment fade-in" -->

---

## Pre-test

### Question 2/2

```cpp
class Gadget {};
void f(const Gadget&) { std::cout << "const Gadget&\n"; }
void f(Gadget&)       { std::cout << "Gadget&\n"; }
void f(Gadget&&)      { std::cout << "Gadget&&\n"; }

template <typename Gadget>
void use(Gadget&& g) { f(g); }

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);
    use(g);
    use(Gadget());
}
```

What will be printed in the screen? Take a pen and jot down your answers.

---

## Move semantics

### Rationale

* Better optimization by avoiding redundant copies
* improved safety by keeping only one instance

---

## New syntax elements

* <!-- .element: class="fragment fade-in" --> <code>auto && value</code> - r-value reference
* <!-- .element: class="fragment fade-in" --> <code>Class(Class &&)</code> - move constructor
* <!-- .element: class="fragment fade-in" --> <code>Class& operator=(Class&&)</code> - move assignment operator
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> auxilary function
* <!-- .element: class="fragment fade-in" --> <code>std::forward()</code> auxilary function

---

## r-value and l-value

```cpp
struct A { int a, b; };

A foo() { return {1, 2}; }

A a;                    // l-value
A{5, 3};                // r-value
foo();                  // r-value
```

---

## r-value and l-value

* <!-- .element: class="fragment fade-in" --> l-value object has a name and address
* <!-- .element: class="fragment fade-in" --> l-value object is persistent, in the next line it can be accessed by name
* <!-- .element: class="fragment fade-in" --> r-value object does not have a name (usually) or address
* <!-- .element: class="fragment fade-in" --> r-value object is temporary, in the next line it will not be accessible

---

## r-value and l-value references

```cpp
struct A { int a, b; };
A foo() { return {1, 2}; }

A a;                    // l-value
A{5, 3};                // r-value
foo();                  // r-value

A & ra = a;             // l-value reference to l-value, OK
A & rb = foo();         // l-value reference to r-value, ERROR
A const& rc = foo();    // const l-value reference to r-value, OK (exception)

A && rra = a;           // r-value reference to l-value, ERROR
A && rrb = foo();       // r-value reference to r-value, OK

A const ca{20, 40};
A const&& rrc = ca;     // const r-value reference to const l-value, ERROR
```

---

## r-value or l-value?

<pre><code class="cpp" data-trim data-noescape>
str1 += str2                    <span class="fragment">// l-value</span>
str1 + str2                     <span class="fragment">// r-value</span>
[](int x){ return x * x; };     <span class="fragment">// r-value</span>
std::move(a);                   <span class="fragment">// r-value</span>
int && a = 4;                   <span class="fragment">// 4 is r-value</span>
</code></pre>

---

## r-value reference is... l-value?

### `int && a = 4;`

* <!-- .element: class="fragment fade-in" --> <code>4</code> is r-value
* <!-- .element: class="fragment fade-in" --> <code>a</code> is r-value reference
* <!-- .element: class="fragment fade-in" --> name <code>a</code> itself is an l-value (has an address, can be referenced lated)
* <!-- .element: class="fragment fade-in" --> but let's not think about it now 😉

---

<!-- .slide: data-background-iframe="https://en.cppreference.com/w/cpp/language/value_category" data-background-interactive -->

<div class="box" style="position: absolute; width: 45%; right: 0; background-color: rgba(0, 0, 0, 0.9); color: #fff; padding: 20px; font-size: 20px; text-align: left;">
    <h2>Value categories in C++</h2>
    <ul>
        <li>lvalue</li>
        <li>prvalue</li>
        <li>xvalue</li>
        <li>glvalue = lvalue | xvalue</li>
        <li>rvalue = prvalue | xvalue</li>
    </ul>
    <p><a href="https://en.cppreference.com/w/cpp/language/value_category">Full list at cppreference.com</a></p>
</div>

---

## Usage of move semantics

```cpp
template <typename T>
class Container {
public:
    void insert(const T& item);  // inserts a copy of item
    void insert(T&& item);       // moves item into container
};

Container<std::string> c;
std::string str = "text";

c.insert(str);              // lvalue -> insert(const std::string&)
                            // inserts a copy of str, str is used later
c.insert(str + str);        // rvalue -> insert(string&&)
                            // moves temporary into container
c.insert("text");           // rvalue -> insert(string&&)
                            // moves temporary into container
c.insert(std::move(str));   // rvalue -> insert(string&&)
                            // moves str into container, str is no longer used
```

---

## Properties of move semantics

* <!-- .element: class="fragment fade-in" --> Transfer all data from the source to the target
* <!-- .element: class="fragment fade-in" --> Leave the source object in an unknown, but safe to delete state
* <!-- .element: class="fragment fade-in" --> The source object should never be used
* <!-- .element: class="fragment fade-in" --> The source object can only be safely destroyed or, if possible, new resource can be assigned to it (eg. <code>reset()</code>)

```cpp
std::unique_ptr<int> pointer1{new int{5}};
std::unique_ptr<int> pointer2 = std::move(pointer1);
*pointer1 = 4;  // Undefined behavior, pointer1 is in moved-from state
pointer1.reset(new int{20});    // OK
```
<!-- .element: class="fragment fade-in" -->

---

## Implementation of move semantic

```cpp
class X : public Base {
    Member m_;

    X(X&& x) : Base(std::move(x)), m_(std::move(x.m_)) {
        x.set_to_resourceless_state();
    }

    X& operator=(X&& x) {
        Base::operator=(std::move(x));
        m_ = std::move(x.m_);
        x.set_to_resourceless_state();
        return *this;
    }

    void set_to_resourceless_state() { /* reset pointers, handlers, etc. */ }
};
```

---

## Implementation of move semantic

### Usual implementation

```cpp
class X : public Base {
    Member m_;

    X(X&& x) = default;
    X& operator=(X&& x) = default;
};
```

---

## Task

Aim: learn how to implement move semantics with manual resource management

Write your own implementation of `unique_ptr`

Let's try online Coding Dojo :)
<!-- .element: class="fragment highlight-green" -->

#### Hints

<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Template class
* <!-- .element: class="fragment fade-in" --> RAII
* <!-- .element: class="fragment fade-in" --> Copy operations not allowed
* <!-- .element: class="fragment fade-in" --> Move operations allowed
* <!-- .element: class="fragment fade-in" --> <a href="https://en.cppreference.com/w/cpp/memory/unique_ptr">Interface functions</a> - at least:
    * <code>T* get() const noexcept</code>
    * <code>T& operator*() const</code>
    * <code>T* operator->() const noexcept</code>
    * <code>void reset(T* = nullptr) noexcept</code>

---

## Rule of 3

If you define at least one of:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> destructor
* <!-- .element: class="fragment fade-in" --> copy constructor 
* <!-- .element: class="fragment fade-in" --> copy assignment operator

it means that you are manually managing resources and <span class="fragment highlight-red">you should implement them all</span>.
<!-- .element: class="fragment fade-in" -->

It will ensure correctness in every context.
<!-- .element: class="fragment fade-in" -->

---

## Rule of 5

Rule of 5 = Rule of 3 + optimizations

* destructor
* copy constructor 
* copy assignment operator
* <!-- .element: class="fragment highlight-green" --> move constructor
* <!-- .element: class="fragment highlight-green" --> move assignment operator

From C++11 use Rule of 5.
<!-- .element: class="fragment fade-in" -->

---

## Rule of 0

Do not implement any of Rule of 5 functions 😎
<!-- .element: class="fragment highlight-green" -->

If you use RAII handlers (like smart pointers), all the copy and move operations will be generated (or deleted) implicitly.
<!-- .element: class="fragment fade-in" -->

Eg. when you have unique_ptr as your class member, copy operations of your class will be automatically blocked, but move operations will be supported.
<!-- .element: class="fragment fade-in" -->

---

## Task

Aim: learn how to refactor code to use RAII and Rule of 0

Write a template class which holds a pointer

* <!-- .element: class="fragment fade-in" --> use raw pointer to manage resource of a template type
* <!-- .element: class="fragment fade-in" --> implement constructor to acquire a resource
* <!-- .element: class="fragment fade-in" --> implement Rule of 3
* <!-- .element: class="fragment fade-in" --> implement Rule of 5
* <!-- .element: class="fragment fade-in" --> implement Rule of 0
  * use proper smart pointer instead of raw pointer
  <!-- .element: class="fragment fade-in" -->

---

## Implementation of `std::move()` and "universal reference"

```cpp
template <typename T>
typename std::remove_reference<T>::type&& move(T&& obj) noexcept {
    using ReturnType = std::remove_reference<T>::type&&;
    return static_cast<ReturnType>(obj);
}
```

* <!-- .element: class="fragment fade-in" --> <code>T&&</code> as a template function parameter is not only r-value reference
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> is a "forwarding reference" or "universal reference" (name proposed by Scott Meyers)
* <!-- .element: class="fragment fade-in" --> <code>T&&</code> in templates can bind to l-values and r-values
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> takes any kind of reference and cast it to r-value reference
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> convert any object into a temporary, so that it can be later matched by the compiler to be passed by an r-value reference

---

## Reference collapsing

When a template is being instantiated reference collapsing may occur

```cpp
template <typename T>
void f(T& item) {  // takes item always as an l-value reference
                    // whatever you pass
    // ...
}

void f(int& & item);   // passing int& as a param -> f(int&)
void f(int&& & item);  // passing int&& as a param -> f(int&)
```

### Reference collapsing rules <!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>T& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T& &&</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &</code> -> <code>T&</code>
* <!-- .element: class="fragment fade-in" --> <code>T&& &&</code> -> <code>T&&</code>

---

## Interface bloat

Trying to optimize for every possible use case may lead to an interface bloat

```cpp
class Gadget;
void f(const Gadget&)     { std::cout << "const Gadget&\n"; }
void f(Gadget&)           { std::cout << "Gadget&\n"; }
void f(Gadget&&)          { std::cout << "Gadget&&\n"; }
void use(const Gadget& g) { f(g); }            // calls f(const Gadget&)
void use(Gadget& g)       { f(g); }            // calls f(Gadget&)
void use(Gadget&& g)      { f(std::move(g)); } // calls f(Gadget&&)

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);       // calls use(const Gadget&) then calls f(const Gadget&)
    use(g);        // calls use(Gadget&) then calls f(Gadget&)
    use(Gadget()); // calls use(Gadget&&) then calls f(Gadget&&)
}
```

Task: Try to improve the `use()` function to catch more types of reference to have less overloads.
<!-- .element: class="fragment fade-in" -->

---

## Perfect Forwarding

Forwarding reference `T&&` + `std::forward()` is a solution to interface bloat.

```cpp
class Gadget;

void f(const Gadget&) { std::cout << "const Gadget&\n"; }
void f(Gadget&)       { std::cout << "Gadget&\n"; }
void f(Gadget&&)      { std::cout << "Gadget&&\n"; }

template <typename Gadget>
void use(Gadget&& g) {
    f(std::forward<Gadget>(g)); // forwards original type to f()
}

int main() {
    const Gadget cg;
    Gadget g;
    use(cg);       // calls use(const Gadget&) then calls f(const Gadget&)
    use(g);        // calls use(Gadget&) then calls f(Gadget&)
    use(Gadget()); // calls use(Gadget&&) then calls f(Gadget&&)
}
```

---

## `std::forward`

Forwarding reference (even bind to r-value) is treated as l-value inside template function

```cpp
template <typename T>
void use(T&& t) {
    f(t);                   // t is treated as l-value unconditionally
}
```
<!-- .element: class="fragment fade-in" --> 

```cpp
template <typename T>
void use(T&& t) {
    f(std::move(t));        // t is treated as r-value unconditionally
}
```
<!-- .element: class="fragment fade-in" --> 

```cpp
template <typename T>
void use(T&& t) {           // pass t as r-value if r-value was passed,
    f(std::forward(t));     // pass as l-value otherwise
}
```
<!-- .element: class="fragment fade-in" --> 

In other words: `std::forward()` restores original reference type.
<!-- .element: class="fragment fade-in" --> 

---

## Knowledge check 🙂

### Template type deduction

<pre><code class="cpp" data-trim data-noescape>
template &lt;typename T&gt;
void copy(T arg) {}

template &lt;typename T&gt;
void reference(T& arg) {}

template &lt;typename T&gt;
void universal_reference(T&& arg) {}

int main() {
    int number = 4;
    copy(number);       <span class="fragment">// int</span>
    copy(5);            <span class="fragment">// int</span>
    reference(number);  <span class="fragment">// int&</span>
    reference(5);       <span class="fragment">// candidate function [with T = int] not viable: expects an l-value for 1st argument</span>
    universal_reference(number);            <span class="fragment">// int&</span>
    universal_reference(std::move(number)); <span class="fragment">// int&&</span>
    universal_reference(5);                 <span class="fragment">// int&&</span>
}
</code></pre>

---

## Copy elision

* <!-- .element: class="fragment fade-in" --> omits copy and move constructors
* <!-- .element: class="fragment fade-in" --> results in zero-copy pass-by-value semantics

---

## Mandatory copy elision from C++17

```cpp
T f() {
    return T();
}
f();             // only one call to default c-tor of T
T x = T(T(f())); // only one call to default c-tor of T, to initialize x
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> in return statement, when the object is temporary (RVO - Return Value Optimisation)
* <!-- .element: class="fragment fade-in" --> in the initialization, when the initializer is of the same class and is temporary

Do not try to "optimize" code by writing `return std::move(sth);`. It may prevent optimizations.
<!-- .element: class="fragment fade-in" -->

[Copy elision on cppreference.com](https://en.cppreference.com/w/cpp/language/copy_elision)
<!-- .element: class="fragment fade-in" -->

---

## RVO and NRVO

```cpp
T f() {
    T t;
    return t;  // NRVO
}
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> NRVO = Named RVO
* <!-- .element: class="fragment fade-in" --> RVO is mandatory from C++17, NRVO not

```cpp
T bar()
{
    T t1{1};
    T t2{2};
    return (std::time(nullptr) % 2) ? t1 : t2;
}  // don't know which object will be elided
```
<!-- .element: class="fragment fade-in" -->

[RVO and NRVO on cpp-polska.pl](https://cpp-polska.pl/post/zarzadzanie-zasobami-w-c-3-rvo-nrvo-i-obowiazkowe-rvo-w-c17)
<!-- .element: class="fragment fade-in" -->

---

## Knowledge check 🤯

```cpp
void foo(int && a);         // r
void foo(int & a);          // l

int a = 5;
```

Which of above functions will be called by below snippets?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(4));</code>
  * r (move is redundant) <!-- .element: class="fragment fade-in" -->

---

## Knowledge check 🤯

```cpp
template <typename T>
void foo(T && a);         // r

template <typename T>
void foo(T & a);          // l

int a = 5;
```

Which of above functions will be called by below snippets?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" --> 
* <code>foo(a);</code>
  * l <!-- .element: class="fragment fade-in" --> 
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" --> 

---

## Knowledge check 🤯

```cpp
template <typename T>
void foo(T && a);         // r

int a = 5;
```

What will happen now?

* <code>foo(4);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(a);</code>
  * r <!-- .element: class="fragment fade-in" -->
* <code>foo(std::move(a));</code>
  * r <!-- .element: class="fragment fade-in" -->

---

## Pre-test answers

### Question 1/2

* <!-- .element: class="fragment fade-in" --> "OK"
* <!-- .element: class="fragment fade-in" --> "OK"
* <!-- .element: class="fragment fade-in" --> "OK"

### Question 2/2

* <!-- .element: class="fragment fade-in" --> <code>const Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>
* <!-- .element: class="fragment fade-in" --> <code>Gadget&</code>

---

## Recap

Mention as many keywords / topics from this session as you can

* <!-- .element: class="fragment fade-in" --> r-value and l-value referencesss
* <!-- .element: class="fragment fade-in" --> Move constructor and move assignment operator
* <!-- .element: class="fragment fade-in" --> RAII
* <!-- .element: class="fragment fade-in" --> Rule of 0, 3, 5
* <!-- .element: class="fragment fade-in" --> <code>std::move()</code> and <code>std::forward()</code>
* <!-- .element: class="fragment fade-in" --> Forwarding reference
* <!-- .element: class="fragment fade-in" --> Reference collapsing
* <!-- .element: class="fragment fade-in" --> Perfect forwarding
* <!-- .element: class="fragment fade-in" --> Copy elision, RVO

---

## Post-work

If you wish to practice more on move semantics and resource management try to implement `shared_ptr`.
You can even try to make it thread safe 😊
You can reach me on Discord if you have any question or if you wish to have a code review.

## Post-test

Please [take this quiz](https://forms.gle/rhGWFrfsDQqbA3kL7) (10-15 min) about 2-5 days after the training.
It will help you recall this session and make it last a little bit longer in your memory.

## Evaluation

Please [fill in the survey about this training](https://forms.gle/AzPbk9iAv4poDrrZ9) (5-10 min) now.
It will help me understand how can I improve this session in future.
