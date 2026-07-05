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
    REQUIRE_THAT(array_shuffle(vector<int>{}, 0), Catch::Matchers::IsEmpty());
}

TEST_CASE("shuffling a  vector with two elements results those same elements in order", "[smoke]") {
    REQUIRE(array_shuffle(vector<int>{1, 2}, 1) == vector<int>{1, 2} );
}

TEST_CASE("shuffling a vector of four elements interleaves those elements")
{
    REQUIRE(array_shuffle(vector<int>{1, 2, 3, 4}, 2) == vector<int>{1, 3, 2, 4} );
}

TEST_CASE("shuffling a vector of more elements interleaves those elements")
{
    REQUIRE(array_shuffle(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5) == vector<int>{1, 6, 2, 7, 3, 8, 4, 9, 5, 10} );
}