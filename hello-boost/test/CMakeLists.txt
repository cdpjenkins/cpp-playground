#set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (Boost_Tests_run test.cpp )
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES})

enable_testing()
add_test(test Boost_Tests_run)
