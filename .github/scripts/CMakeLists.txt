cmake_minimum_required(VERSION 3.14)
enable_testing()
project(homework_tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COMPILER_FLAGS
    -Wall
    -Werror
    -Wextra
    -Wconversion
    -Wshadow
    -pedantic)
set(LINKER_FLAGS
    -fsanitize=address
    -fsanitize=undefined)

include(functions.cmake)

set(HOMEWORK_DIR ../../shapes)

build_test(${TASK} ${HOMEWORK_DIR})
