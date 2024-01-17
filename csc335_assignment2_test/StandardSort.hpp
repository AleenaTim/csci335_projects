/******************************************************************************
File            : StandardSort.hpp
Title           : Project 2: Sorting
Author          : Aleena Tim
Created on      : 12/12/2023
******************************************************************************/
#include <vector>
#include <chrono>
#include <algorithm>

/**
 * @brief Standard Sort will sort a vector of ints, time the duration in milliseconds and return the median
 *
 * @param nums Reference to a vector of integers to be sorted
 * @param duration Reference to an integer where the duration of the sort operation will be stored (in milliseconds)
 * @return The median value after completing the standard sort algorithm
 */
int standardSort(std::vector<int> &nums, int &duration)
{
    // Record the start time
    auto time_start = std::chrono::steady_clock::now();
    // Sort on the vector using std::sort
    std::sort(nums.begin(), nums.end());
    // Calculate the index of the median in the sorted vector
    int i = nums.size() / 2 - (nums.size() % 2 == 0);
    // Retrieve the median value from the sorted vector
    int median = nums[i];
    // Record the end time after the sort
    auto time_end = std::chrono::steady_clock::now();
    // Calculate the duration of the sorting operation in milliseconds
    auto time_result = time_end - time_start;
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_result).count();
    // Return the median value
    return median;
}
