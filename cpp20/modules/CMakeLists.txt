cmake_minimum_required(VERSION 3.10)

# g++ -std=c++2a Circle.cppm -Wall -Wpedantic -Wextra -fmodules-ts  --precompile -o Circle.pcm -fmodule-file=Shape.pcm
# g++ -std=c++2a *.cpp -Wall -Wpedantic -Wextra -fmodules-ts -fmodule-file=Shape.pcm -fmodule-file=Circle.pcm

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_FLAGS -Wall -Wpedantic -Wextra)
set(COMPILER g++)
project(shapes)

add_custom_target(Shape.pcm ALL
    COMMAND ${COMPILER} -std=c++2a ${CMAKE_CURRENT_SOURCE_DIR}/Shape.cppm ${CXX_FLAGS} -fmodules-ts --precompile -o Shape.pcm
)

add_custom_target(Circle.pcm ALL
    COMMAND ${COMPILER} -std=c++2a ${CMAKE_CURRENT_SOURCE_DIR}/Circle.cppm ${CXX_FLAGS} -fmodules-ts --precompile -o Circle.pcm -fmodule-file=Shape.pcm
    DEPENDS Shape.pcm
)

add_custom_target(Rectangle.pcm ALL
    COMMAND ${COMPILER} -std=c++2a ${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.cppm ${CXX_FLAGS} -fmodules-ts --precompile -o Rectangle.pcm -fmodule-file=Shape.pcm
    DEPENDS Shape.pcm
)

add_custom_target(Square.pcm ALL
    COMMAND ${COMPILER} -std=c++2a ${CMAKE_CURRENT_SOURCE_DIR}/Square.cppm ${CXX_FLAGS} -fmodules-ts --precompile -o Square.pcm -fmodule-file=Shape.pcm -fmodule-file=Rectangle.pcm
    DEPENDS Rectangle.pcm Shape.pcm
)

add_custom_target(shapes ALL
    COMMAND ${COMPILER} -std=c++2a ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${CXX_FLAGS} -fmodules-ts -o shapes -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Shape.pcm -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Circle.pcm -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Rectangle.pcm -fmodule-file=${CMAKE_CURRENT_BINARY_DIR}/Square.pcm
    DEPENDS Shape.pcm Rectangle.pcm Circle.pcm Square.pcm
)
