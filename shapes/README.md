# Modern C++ exercises

## Compilation and running the project

Check your g++ version by typing:
`> g++ --version`
It should be >= 7.0

```bash
> mkdir build
> cd build
> cmake ..
> make
> ./shapes
```

## Tasks

1. `static_assert`:
    Assert that `M_PI` used in `Circle.cpp` file is not equal to `3.14`
2. `using` alias:
    Change `typedef` to `using` alias
3. scoped `enum`:
    Write a new scoped enum named Color and define in it 3 colors of your choice. Inherit from unsigned char.
    Add a new field: `Color color` in the `Shape` class, so that every shape has it's own defined color.
4. `auto`:
    Use `auto`, wherever you should.
5. range-based for loop:
    Use range-based for loops, wherever possible.
6. move semantics:
    Group task:
    Implement your own unique_ptr. Requirements:
    - Template class
    - RAII
    - Copy operations not allowed
    - Move operations allowed
    - Interface functions - at least:
        - T* get()
        - T& operator*()
        - T* operator->()

    Add move constructors and move assignment operators to all shapes.
    Mark them as `noexcept`.
    What about Rule of 5?
    Move some shapes into the collection.
7. `default`, `delete`:
    Mark copy constructors as `default`.
    Delete `getY()` method in `Square` and all default constructors of shapes
8. `final`, `override`:
    Mark `Circle` class as `final`
    Mark `getX()` in `Rectangle` as `final`. What is the problem?
    Mark all overridden virtual methods. Can you spot the problem?
9. `constexpr`:
    Write a function that calculates n-th Fibonacci's number. Do not mark it `constexpr`.
    In the first line of `main()` add computing 45-th Fibonacci's number. Measure the time of program execution (time ./shapes)
    Mark fibonacci function as `constexpr`, compile the program and measure the time of execution once again.
    If you can't see a big difference assign the result to the constexpr variable.
10. uniform initialization:
    Use `initializer_list` to initialize the collection.
    Add a new constructor to Shape - `Shape(Color c)`. What happens?
    Use constructor inheritance to allow initialization of all shapes providing only a `Color` as a parameter. Create some shapes providing `Color` only param.
    Add in-class field initialization for all shapes to safely use inherited constructor.
11. SFINAE
    Write a function that allows inserting only subclasses of Shape to the collection. Other parameter types should not compile. Use SFINAE. Find proper type_traits.
12. attributes:
    Add a new method `double getPi()` in `Circle` class, which returns a PI number. Mark it as deprecated.
13. `noexcept`:
    Mark some `getArea()` and `getPerimeter()` methods as `noexcept`
14. `alignas`, `alignof`
    Change the alignment of the `Circle` class to 128.
    Print the alignment in `main()` function.
    Change the alignment to 2.
    Print the alignment.
15. delegating constructors:
    Add a new constructor, which takes also the previously defined Color of a shape. You can use a default parameter for Color.
    Delegate a call in the old constructor to the new one.
16. lambda functions:
    Change functions from `main.cpp` into lambdas (`sortByArea`, `perimeterBiggerThan20`, `areaLessThan10`)
    Change lambda `areaLessThan10` into lambda `areaLessThanX`, which takes `x = 10` on a capture list. What is the problem?
    Use `std::function` to solve the problem.
17. structured bindings:
    Create an `std::map<shared_ptr<Shape>, double>` that will hold a shape and it's perimeter.
    Use structured bindings to iterate over this collection and display shape info (call `print()` member function) and a perimeter.
18. variadic templates:
    Write a factory method which should work like `std::make_shared`.
    It should have below signature:

    ```cpp
    template<class DerivedType, class... Arguments>
    std::shared_ptr<Shape> make_shape(Arguments&&... args);
    ```

    Inside, it should create a `shared_ptr` to DerivedType and pass all arguments into constructor of DerivedType via perfect forwarding.
