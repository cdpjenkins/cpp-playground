cmake_minimum_required(VERSION 4.2)
project(playground)

set(CMAKE_CXX_STANDARD 26)

add_executable(playground main.cpp)

find_package(Catch2 CONFIG REQUIRED)

enable_testing()

add_executable(tests tests/tests.cpp
        tests/tests.cpp
        tests/tests.cpp
        tests/tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)
