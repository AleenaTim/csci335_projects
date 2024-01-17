#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

class Node{
    public:
    int group;
    double x, y;

    Node(int group, double x, double y) : group(group), x(x), y(y) {}

    double distanceLength(const Node& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
};

