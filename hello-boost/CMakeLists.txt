cmake_minimum_required(VERSION 3.24)
project(hello_boost)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(hello_boost main.cpp)

target_link_libraries(hello_boost ${Boost_LIBRARIES})

add_subdirectory(test)
