//
// Created by Chris Jenkins on 05/07/2026.
//

#include "array_shuffle.h"

#include <vector>
#include <bit>
using namespace std;

// Solution from https://www.linkedin.com/feed/update/activity:7478882097231777792/
void fast_shuffle(vector<int>& array, int n)
{
    constexpr unsigned int max_value = 1000;
    constexpr int bit_width = std::bit_width(max_value);
    constexpr int mask = (1 << bit_width) - 1;

    for (int i = 0, j = 0; i < n; i++, j += 2)
    {
        array[j] |= (array[i] & mask) << bit_width;
        array[j + 1] |= (array[i + n] & mask) << bit_width;
    }

    for (int i = 0; i < n*2; i++)
    {
        array[i] >>= bit_width;
    }
}

void array_shuffle(vector<int>& array, int n)
{
    fast_shuffle(array, n);
}
