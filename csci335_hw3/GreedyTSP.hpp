/******************************************************************************
File            : GreedyTSP.hpp
Title           : Project 3: Traveling Salesman
Author          : Aleena Tim
Created on      : 12/21/2023
******************************************************************************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <chrono>
#include <functional>
#include "Node.hpp"

#ifndef GREEDYTSP_HPP
#define GREEDYTSP_HPP

struct Edge {
    int from;
    int to;
    double weight;

    Edge(int f, int t, double w) : from(f), to(t), weight(w) {}

    bool operator<(const Edge& e) const {
        return weight < e.weight;
    }
};

double sumOfDistance(const Node& a, const Node& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool formsCycle(const std::vector<Edge>& edges, int n, const Edge& newEdge) {
    std::vector<int> parents(n + 1, -1);

    std::function<int(int)> findParent = [&](int node) {
        if (parents[node] == -1) return node;
        return parents[node] = findParent(parents[node]);
    };

    int parentFrom = findParent(newEdge.from);
    int parentTo = findParent(newEdge.to);

    if (parentFrom == parentTo) {
        return true; 
    }

    parents[parentFrom] = parentTo;
    return false;
}

void greedyTSP(std::string fileName) {

    std::vector<Node> nodes;

    std::ifstream file(fileName);

    std::string line;
    int group;
    double x, y;

    while(std::getline(file, line)){
        std::istringstream iss(line);
        if(iss >> group >> x >> y){
            nodes.push_back(Node(group, x, y));
        }
    }
    int n = nodes.size();
    if (n == 0) return;

    // Record the end time for performance measurement
    auto start = std::chrono::high_resolution_clock::now();
    
    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.emplace_back(i + 1, j + 1, sumOfDistance(nodes[i], nodes[j]));
        }
    }

    std::sort(edges.begin(), edges.end());

    std::vector<Edge> cEdges;
    for (const auto& edge : edges) {
        if (!formsCycle(cEdges, n, edge)) {
            cEdges.push_back(edge);
            if (cEdges.size() == n - 1) break; 
        }
    }
    // Record the end time for performance measurement
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    double sumOfDistance = 0;

    for (const auto& edge : cEdges) {
        std::cout << "Edge from " << edge.from << " to " << edge.to << " of weight " << edge.weight << std::endl;
        sumOfDistance += edge.weight;
    }
    std::cout << "Total Distance: " << sumOfDistance << std::endl;
    // Calculate and output the total sumOfDistance and duration of the algorithm

    std::cout << "Time in ms: " << duration.count() << std::endl;
}

#endif
