#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "GreedyTSP.hpp"
//#include "GreedyTSP.hpp"

int main(){
    // Open the file
    std::string filename = "ar9152.tsp";
    std::ifstream inputFile(filename);
    
    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1; // Return an error code
    }
    else {
        greedyTSP(filename);
    }
    // Close the file
    inputFile.close();
}