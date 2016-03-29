-1. Przygotuj środowisko (tylko na PWr)
    > chmod +x install_packages.sh
    > su (hasło: nokia)
    > ./install_packages.sh
    > exit

0. Skompiluj i uruchom projekt
    > mkdir build
    > cd build
    > cmake ..
    > make
    > ./modern_cpp

Jeśli masz gcc < 6.0 musisz dodać flagę kompilacji -std=c++14. W pliku CMakeLists.txt dopisz na końcu:
    add_definitions(-std=c++14)

1. Zamień użycia typedef na aliasy using
2. Zamień wszystkie NULLe/0 na nullptry
4. Użyj auto tam, gdzie można uprościć kod.
5. Użyj pętli po kolekcji tam, gdzie to możliwe.
6. Użyj słów kluczowych default i delete tam, gdzie to możliwe.
7. Użyj słów kluczowych override i final tam, gdzie to możliwe. Czy widzisz jakiś problem w kodzie?
8. W klasie Circle dopisz funkcję double getPi(), która powinna zwrócić liczbę pi i oznacz ją jako deprecated.
9. Dopisz modyfikator noexcept do definicji metod getArea i getPerimeter.
10. Użyj listy inicjalizacyjnej do zainicjalizowania wektora.
11. Zamień zwykłe wskaźniki na shared_ptry. 
13. Zamień funkcje z pliku main.cpp: sortByArea, perimeterBiggerThan20, areaLessThan10 na funkcje lambda.

Praca domowa:
11. Dodaj scoped enuma Color i zdefiniuj w nim 3 wybrane przez siebie kolory. Dodaj pole color typu Color do klasy Shape, aby każda figura miała także zdefiniowany kolor.
12. Dopisz nowe konstruktory do klas figur, aby podawać w nich także kolor. Wykorzystaj delegowanie konstruktorów, aby wywołały one wcześniej istniejące konstruktory klas.
13. Napisz funkcję fabrykującą (factory method), która będzie działać na podobnej zasadzie jak make_shared.
Funkcja ta ma mieć poniższą sygnaturę:
  template<class DerivedType, class... Arguments> std::shared_ptr<Shape> make_shape(Arguments&&... args);
Wewnątrz, powinna ona tworzyć shared_ptr na typ DerivedType i przekazywać do konstruktora tego typu argumenty args poprzez perfect forwarding.
