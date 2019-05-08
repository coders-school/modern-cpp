cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(modern_cpp)

set(SRC_LIST
    Circle.cpp
    Circle.hpp
    Rectangle.cpp
    Rectangle.hpp
    Square.cpp
    Square.hpp
    Shape.cpp
    Shape.hpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
add_compile_options(${PROJECT_NAME} -Wall -Werror -Wpedantic -Wextra)
