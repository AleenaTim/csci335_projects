/******************************************************************************
File            : QuickSelect.hpp
Title           : Project 2: Sorting
Author          : Aleena Tim
Created on      : 12/12/2023
******************************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

int medianIndex(int i) {
    if (i % 2 == 0) {
        return i / 2 - 1;
    } else {
        return i / 2;
    }
}

std::vector<int>::iterator medianOfThree(std::vector<int>::iterator first, std::vector<int>::iterator mid, std::vector<int>::iterator last) {
    if (*first < *mid) {
        if (*mid < *last) return mid;
        else if (*first < *last) return last;
        else return first;
    } else {
        if (*first < *last) return first;
        else if (*mid < *last) return last;
        else return mid;
    }
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto pivot = medianOfThree(low, low + std::distance(low, high) / 2, high);
    int pivotValue = *pivot;

    std::iter_swap(pivot, high);

    auto i = low;
    auto j = high;

    while (true) {
        while (i < j && *i < pivotValue) {
            i++;
        }
        while (j > i && *j >= pivotValue) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(*i, *j);
    }

    std::swap(*i, *high);

    return i;
}

int quickSelectHelper(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int n) {
    if (high - low < 10) {
        std::sort(low, high + 1); 
        return *(low + n);
    }

    auto partition = hoarePartition(nums, low, high);
    int distance = std::distance(low, partition);

    if (distance == n) {
        return *partition;
    } else if (distance > n) {
        return quickSelectHelper(nums, low, partition - 1, n);
    } else {
        return quickSelectHelper(nums, partition + 1, high, n - distance - 1);
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    int n = medianIndex(nums.size());

    auto time_start = std::chrono::high_resolution_clock::now();

    int median = quickSelectHelper(nums, nums.begin(), nums.end() - 1, n);

    auto time_end = std::chrono::high_resolution_clock::now();

    duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();

    return median;
}
