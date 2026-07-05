cmake_minimum_required(VERSION 4.2)
project(playground)

set(CMAKE_CXX_STANDARD 26)

add_executable(playground
        src/main.cpp
        src/array_shuffle.cpp
        src/array_shuffle.h)

find_package(Catch2 CONFIG REQUIRED)

enable_testing()

add_executable(tests
        tests/tests.cpp
        tests/array_shuffle_tests.cpp
        src/array_shuffle.cpp
        src/array_shuffle.h)
target_include_directories(tests PRIVATE src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)
