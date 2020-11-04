<!-- .slide: data-background="#111111" -->

# Pre-test

## Answers

___

## 1. What is the type of variable `v`?

```cpp
int i = 42;
const auto v = &i;
```

1. <!-- .element: class="fragment highlight-red" --> <code>const int</code>
1. <!-- .element: class="fragment highlight-red" --> <code>const int&</code>
1. <!-- .element: class="fragment highlight-green" --> <code>const int*</code>
1. <!-- .element: class="fragment highlight-red" --> other

___

## 2. Which of the following initializations are valid in C++14?

```cpp
struct P { int a, b };
```

1. <!-- .element: class="fragment highlight-green" --> <code>int values[] = { 1, 2, 3, 4, 5 };</code>
1. <!-- .element: class="fragment highlight-green" --> <code>P v = { 1, 4 };</code>
1. <!-- .element: class="fragment highlight-green" --> <code>P v{1, 4};</code>
1. <!-- .element: class="fragment highlight-red" --> <code>P v(1, 4);</code>
1. <!-- .element: class="fragment highlight-green" --> <code>std::vector&lt;int> v = { 1, 2, 3, 4 };</code>
1. <!-- .element: class="fragment highlight-red" --> <code>std::vector&lt;int> v(1, 2, 3, 4);</code>
1. <!-- .element: class="fragment highlight-red" --> <code>int v[] = { 1, 3, 5, 6.6 };</code>

___

## 3. Which of the following elements can be defined as deleted (`= delete;`)?

1. <!-- .element: class="fragment highlight-green" --> default constructor
1. <!-- .element: class="fragment highlight-green" --> copy constructor
1. <!-- .element: class="fragment highlight-green" --> move constructor
1. <!-- .element: class="fragment highlight-green" --> copy assignment operator
1. <!-- .element: class="fragment highlight-green" --> move assignment operator
1. <!-- .element: class="fragment highlight-green" --> destructor
1. <!-- .element: class="fragment highlight-green" --> free function
1. <!-- .element: class="fragment highlight-green" --> class method
1. <!-- .element: class="fragment highlight-red" --> class member object

___

## Post-test

The link to post-test will be sent to you in a next week.

It's better to forget some of the content and refresh your knowledge later.

It enhances knowledge retention :)

___

## Homework

Take a look into `README.md` file from modern_cpp repository. You can complete all tasks and raise a Pull Request if you wish me to check your homework.

___

## Feedback

* What could be improved in this training?
* What was the most valuable for you?
* [Training evaluation](https://forms.gle/qEZFvYKdgbxkyxYj7)
