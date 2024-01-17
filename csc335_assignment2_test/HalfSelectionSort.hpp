/******************************************************************************
File            : HalfSelectionSort.hpp
Title           : Project 2: Sorting
Author          : Aleena Tim
Created on      : 12/12/2023
******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

int medianIndex(int i) {
    if (i % 2 == 0) {
        return i / 2 - 1;
    } else {
        return i / 2;
    }
}

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    auto time_start = std::chrono::steady_clock::now();

    int n = nums.size();

    for (int i = 0; i <= medianIndex(n); ++i) {
        int minimum_index = i;

        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minimum_index]) {
                minimum_index = j;
            }
        }

        if (minimum_index != i) {
            std::swap(nums[i], nums[minimum_index]);
        }
    }

    auto time_end = std::chrono::steady_clock::now();

    auto time = time_end - time_start;
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

    return nums[medianIndex(n)];
}
