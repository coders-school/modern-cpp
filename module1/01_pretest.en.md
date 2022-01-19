<!-- .slide: data-background="#111111" -->

# Pre-test

___

## 1. What is the type of variable `v`?

```cpp
int i = 42;
const auto v = &i;
```

1. `const int`
1. `const int&`
1. `const int*`
1. other

___

## 2. Which of the following initializations are valid in C++14?

```cpp
struct P { int a, b };
```

1. `int values[] = { 1, 2, 3, 4, 5 };`
1. `P v = { 1, 4 };`
1. `P v{1, 4};`
1. `P v(1, 4);`
1. `std::vector<int> v = { 1, 2, 3, 4 };`
1. `std::vector<int> v(1, 2, 3, 4);`
1. `int v[] = { 1, 3, 5, 6.6 };`

___

## 3. Which of the following elements can be defined as deleted (`= delete;`)?

1. default constructor
1. copy constructor
1. move constructor
1. copy assignment operator
1. move assignment operator
1. destructor
1. free function
1. class method
1. class member object
