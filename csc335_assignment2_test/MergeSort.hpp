/******************************************************************************
File            : MergeSort.hpp
Title           : Project 2: Sorting
Author          : Aleena Tim
Created on      : 12/12/2023
******************************************************************************/
#include <vector>
#include <chrono>

void mergeSortHelper(std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (low >= high) return;

    size_t dist = std::distance(low, high);
    std::vector<int>::iterator mid = std::next(low, dist / 2);

    mergeSortHelper(low, mid);
    mergeSortHelper(mid + 1, high);

    std::vector<int> temp;
    temp.reserve(dist + 1);  

    std::merge(low, mid + 1, mid + 1, high + 1, std::back_inserter(temp));

    std::copy(temp.begin(), temp.end(), low);
}

int mergeSort(std::vector<int>& nums, int& duration) {
    auto time_start = std::chrono::steady_clock::now();

    mergeSortHelper(nums.begin(), nums.end() - 1);

    auto time_end = std::chrono::steady_clock::now();

    auto time = time_end - time_start;
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();

    int i = nums.size() / 2 - (nums.size() % 2 == 0);

    return nums[i];
}
