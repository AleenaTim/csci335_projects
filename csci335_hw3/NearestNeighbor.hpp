/******************************************************************************
File            : NearestNeighbor.hpp
Title           : Project 3: Traveling Salesman
Author          : Aleena Tim
Created on      : 12/21/2023
******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include "Node.hpp"
#ifndef NEARESTNEIGHBOR_HPP
#define NEARESTNEIGHBOR_HPP

// Function to find the closest node in the list to the current node and remove i from the list
Node ifClosestNode(std::vector<Node>::iterator& current, std::vector<Node>& list){
    auto closest = list.end();
    double minDistance = std::numeric_limits<double>::max();

    // Iterate through the list of nodes
    for(auto i = list.begin(); i != list.end(); ++i){
        if(i != current){
            double distance = current->distanceLength(*i);
            
            // Update closest if a node with a shorter distance is found
            if(distance < minDistance){
                minDistance = distance;
                closest = i;
            }
        }
    }
    
    // Save the closest node, erase i from the list, and return i
    Node closestNode = *closest;
    list.erase(closest);
    return closestNode;
}

// Function to find the nearest neighbor path for the Traveling Salesman Problem
void nearestNeighbor(std::string fileName){
    
    // Vector to store nodes from the input file
    std::vector<Node> nodes;

    // Open the input file
    std::ifstream file(fileName);

    // Read data from the file and populate the nodes vector
    std::string line;
    int group;
    double x, y;

    while(std::getline(file, line)){
        std::istringstream iss(line);
        if(iss >> group >> x >> y){
            nodes.push_back(Node(group, x, y));
        }
    }

    // Check if the nodes vector is empty
    if(nodes.empty()) return;

    // Vector to store the visited nodes in the nearest neighbor path
    std::vector<Node> visited;
    double sumOfDistance = 0;

    // Start with the first node in the vector and erase i from the nodes vector
    visited.push_back(nodes.front());
    nodes.erase(nodes.begin());

    // Record the start time for performance measurement
    auto start = std::chrono::high_resolution_clock::now();

    // Pointer to the current node in the path
    auto current = visited.begin();

    // Find the nearest neighbor for each remaining node
    while(!nodes.empty()){
        Node closestNode = ifClosestNode(current, nodes);
        sumOfDistance += current->distanceLength(closestNode);
        visited.push_back(closestNode);
        current = visited.end() - 1;
    }

    // Complete the path by connecting the last and first nodes
    sumOfDistance += visited.front().distanceLength(visited.back());
    visited.push_back(visited.front());

    // Record the end time for performance measurement
    auto end = std::chrono::high_resolution_clock::now();
    
    // Output the visited nodes in the nearest neighbor path
    for(const auto& node : visited){
        std::cout << node.group << " ";
    }
    std::cout << std::endl;
    
    // Calculate and output the total distance and duration of the algorithm
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Total Distance: " << sumOfDistance << std::endl;
    std::cout << "Time in ms: " << duration.count() << std::endl;
}
#endif
