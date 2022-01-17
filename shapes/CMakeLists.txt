cmake_minimum_required(VERSION 3.11.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main # release-1.10.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

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

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)

# shhh... don't ask about commented section ;)
# target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
