//
// Created by Chris Jenkins on 05/07/2026.
//

#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_all.hpp>
using namespace Catch::Matchers;

#include "array_shuffle.h"

#include <vector>
using namespace std;

TEST_CASE("shuffling an empty vector results in an empty vector", "[smoke]") {
    vector<int> vec{};
    array_shuffle(vec, 0);
    REQUIRE_THAT(vec, Catch::Matchers::IsEmpty());
}

TEST_CASE("shuffling a  vector with two elements results those same elements in order", "[smoke]") {
    vector vec{1, 2};
    array_shuffle(vec, 1);
    REQUIRE(vec == vector<int>{1, 2} );
}

TEST_CASE("shuffling a vector of four elements interleaves those elements")
{
    vector vec{1, 2, 3, 4};
    array_shuffle(vec, 2);
    REQUIRE(vec == vector<int>{1, 3, 2, 4} );
}

TEST_CASE("shuffling a vector of more elements interleaves those elements")
{
    vector vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array_shuffle(vec, 5);
    REQUIRE(vec == vector<int>{1, 6, 2, 7, 3, 8, 4, 9, 5, 10} );
}
