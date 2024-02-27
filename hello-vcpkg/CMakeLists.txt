cmake_minimum_required(VERSION 3.10)

project(hello-vcpkg)

find_package(fmt CONFIG REQUIRED)

add_executable(hello-vcpkg HelloVCPKG.cpp)

target_link_libraries(hello-vcpkg PRIVATE fmt::fmt)

