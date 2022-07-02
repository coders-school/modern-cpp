function(build_test NAME HOMEWORK_DIR)
    set(SRC
        ${HOMEWORK_DIR}/Circle.cpp
        ${HOMEWORK_DIR}/Rectangle.cpp
        ${HOMEWORK_DIR}/Shape.cpp
        ${HOMEWORK_DIR}/Square.cpp)
    add_executable(${NAME} tests/${NAME}_tests.cpp ${SRC})
    target_compile_options(${NAME} PRIVATE ${COMPILER_FLAGS})
    target_link_options(${NAME} PRIVATE ${LINKER_FLAGS})
    target_include_directories(${NAME} PRIVATE ${HOMEWORK_DIR})

    link_test_framework(${NAME})
endfunction()

function(link_test_framework TARGET)
    if(TEST_FRAMEWORK STREQUAL gtest)
        include(FetchContent)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG        main
        )

        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
        include(GoogleTest)

        target_link_libraries(${TARGET} PUBLIC gtest_main)

    elseif(TEST_FRAMEWORK STREQUAL catch2)
        include(FetchContent)
        FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG        v3.0.0-preview4
        )

        FetchContent_MakeAvailable(catch2)
        target_link_libraries(${TARGET} PRIVATE Catch2::Catch2WithMain gcov)

    else()
        message(FATAL_ERROR "Unknown or not set test framework")
    endif()
endfunction()
