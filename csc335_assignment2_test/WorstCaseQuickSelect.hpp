/******************************************************************************
File            : WorstCaseQuickSelect.hpp
Title           : Project 2: Sorting
Author          : Aleena Tim
Created on      : 12/12/2023
******************************************************************************/
#include <vector>

std::vector<int> worstCaseQuickSelect(void) {
    std::vector<int> nums;
    for (int i = 20000; i >= 1; i--) {
        nums.push_back(i);
    }
    return nums;
}
