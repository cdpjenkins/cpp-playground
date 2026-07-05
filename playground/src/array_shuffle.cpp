//
// Created by Chris Jenkins on 05/07/2026.
//

#include "array_shuffle.h"

#import <vector>
using namespace std;

std::vector<int> array_shuffle(std::vector<int> array, int n)
{
    vector<int> result{};

    for (int i = 0; i < n; i++)
    {
        result.push_back(array[i]);
        result.push_back(array[i + n]);
    }

    return result;
}
