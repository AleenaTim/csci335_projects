/******************************************************************************
File            : HalfHeapSort.hpp
Title           : Project 2: Sorting
Author          : Aleena Tim
Created on      : 12/12/2023
******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

void percDown(vector<int>& heap, vector<int>::size_type hole) {
    int l;
    int temp = heap[0];

    for(; hole * 2 < heap.size(); hole = l) {
        l = hole * 2;
        if(l + 1 < heap.size() && heap[l] > heap[l + 1]) {
            l++;
        }   
        if(temp > heap[l]) {
            heap[hole] = heap[l];
        }
        else{
            break;
        }
    }

    heap[hole] = temp;
}

void buildHeap(vector<int>& heap) {
    for(int i = (heap.size()-1)/2; i > 0; i--) {
        heap[0] = heap[i];
        percDown(heap, i);
    }
}

int halfHeapSort(vector<int>& nums, int& duration) {
    auto time_start = chrono::steady_clock::now();

    nums.push_back(nums[0]);

    buildHeap(nums);

    int mid = (nums.size()-2)/2;

    for(int i = 0; i < mid; i++) {
        nums[0] = nums[nums.size() - 1];
        nums.pop_back();
        percDown(nums, 1);
    }

    auto time_end = chrono::steady_clock::now();

    duration = chrono::duration<double, milli> (time_end - time_start).count();

    return nums[1];
}
