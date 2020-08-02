cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(shapes)

set(SRC_LIST
    Circle.cpp
    Rectangle.cpp
    Square.cpp
    Shape.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
add_compile_options(${PROJECT_NAME} -Wall -Werror -Wpedantic -Wextra)
# shhh... don't ask about commented section ;)
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
