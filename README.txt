0. Compile and run the project
    > mkdir build
    > cd build
    > cmake ..
    > make
    > ./modern_cpp

Check your g++ version by typing:
    > g++ --version
It should be >= 5.0

1. static_assert:
    Assert that M_PI defined in math library in Circle.cpp file is not equal to 3.14
2. nullptr:
    Change all NULL/0 to nullptrs
3. using alias:
    Change typedefs to using alias
4. scoped enum:
    Write new scoped enum named Color and define in it 3 colors of your choice.
    Add new field: Color color in Shape class, so that every shape has it's own defined color.
5. auto:
    Use auto, wherever you should.
6. range based for loop:
    Use range based for loops, wherever possible.
7. default, delete:
    Mark copy constructors as default.
    Delete getY() method in Square and all default constructors of shapes
8. override, final:
    Mark Circle class as final
    Mark getX() in Rectangle as final
    Mark all overriden virtual methods. Can you spot the problem?
9. attributes:
    Add a new method `double getPi()` in Circle class, which returns a PI number. Mark it as deprecated.
10. noexcept:
    Mark some getArea() and getPerimeter() methods as noexcept
11. constexpr:
    Write a function that calculates n-th Fibonacci's number. Do not mark it constexpr.
    Add in first line of main() computing 45-th Fibonacci's number. Measure the time of program execution (time ./modern_cpp)
    Mark fibonacci function as constexpr, compile the program and measure the time of execution once again.
12. alignas, alignof
    Change the alignment of Cicle class to 128.
    Print the alignment in main() function.
    Change the alignment to 2.
    Print the alignment.
13. uniform initialization:
    Use initializer_list to initialize the collection.
14. smart pointer
    Use valgrind to check and identify memory leaks.
    Replace raw pointers with shared_ptrs.
    Add a new unique_ptr to Circle and find a way to add it to the collection
15. move semantics:
    Add move constructors and move assignment operators to all shapes.
    Mark them as noexcept
    Move some shapes into the collection
16. delegating constructors:
    Add a new constructor, which takes also the previously defined Color of a shape. You can use a default parameter for Color.
    Delegate a call in old constructor to the new one.
17. lambda functions:
    Change functions from main.cpp into lambdas (sortByArea, perimeterBiggerThan20, areaLessThan10)
    Change lambda areaLessThan10 into lambda areaLessThanX, which takes int x = 10 on a capture list.
18. variadic templates:
    Write a factory method which should work like std::make_shared.
    It should have below signature:
        template<class DerivedType, class... Arguments> std::shared_ptr<Shape> make_shape(Arguments&&... args);
    Inside, it should create a shared_ptr to DerivedType and pass all arguments into construtor of DerivedType via perfect forwarding.
        
