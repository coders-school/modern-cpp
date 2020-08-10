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

___

## Rule of 5

Rule of 5 = Rule of 3 + optimizations

* destructor
* copy constructor 
* copy assignment operator
* <!-- .element: class="fragment highlight-green" --> move constructor
* <!-- .element: class="fragment highlight-green" --> move assignment operator

From C++11 use Rule of 5.
<!-- .element: class="fragment fade-in" -->

___

## Rule of 0

Do not implement any of Rule of 5 functions 😎
<!-- .element: class="fragment highlight-green" -->

If you use RAII handlers (like smart pointers), all the copy and move operations will be generated (or deleted) implicitly.
<!-- .element: class="fragment fade-in" -->

Eg. when you have unique_ptr as your class member, copy operations of your class will be automatically blocked, but move operations will be supported.
<!-- .element: class="fragment fade-in" -->

___

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
