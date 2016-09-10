0. Compile and run application:
    > mkdir build
    > cd build
    > cmake ..
    > make
    > ./modern_cpp

If you have gcc < 6.0 you need to add new compilation flag -std=c++14. In CMakeLists.txt add the line:
    add_definitions(-std=c++14)


1. Change all NULLe/0 to nullptrs
2. Change typedefs to using alias
3. Write new scoped enum named Color and define in it 3 colors of your choice.
Add new field: Color color in Shape class, so that every shape has it's own defined color.
4. Use auto, wherever you should.
5. Use range based for loops, wherever possible.
6. Dopisz do struktury rectangle modyfikator alignas i sprawdź wyrównanie za pomocą alignof.
7. Użyj słów kluczowych default i delete tam, gdzie to możliwe.
8. Użyj słów kluczowych override i final tam, gdzie to możliwe. Czy widzisz jakiś problem w kodzie?
9. W klasie Circle dopisz funkcję double getPi(), która powinna zwrócić liczbę pi i oznacz ją jako deprecated.
10. Dopisz modyfikator noexcept do definicji metod getArea i getPerimeter.
11. Użyj constexpr tam, gdzie to możliwe.
12. Użyj listy inicjalizacyjnej do zainicjalizowania wektora.
13. Zamień zwykłe wskaźniki na shared_ptry.
14. Zamień konstruktory kopiujące, tak, aby wykorzystywały delegowanie konstruktorów i wywoływały inne istniejące konstruktory.
15. Dopisz nowe konstruktory do klas figur, aby podawać w nich także kolor. Wykorzystaj delegowanie konstruktorów, aby wywołały one wcześniej istniejące konstruktory klas.
16. Zamień funkcje z pliku main.cpp: sortByArea, perimeterBiggerThan20, areaLessThan10 na funkcje lambda.
17. Napisz funkcję fabrykującą (factory method), która będzie działać na podobnej zasadzie jak make_shared.
Funkcja ta ma mieć poniższą sygnaturę:
  template<class DerivedType, class... Arguments> std::shared_ptr<Shape> make_shape(Arguments&&... args);
Wewnątrz, powinna ona tworzyć shared_ptr na typ DerivedType i przekazywać do konstruktora tego typu argumenty args poprzez perfect forwarding.
18. Multithreading?
