#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <ctime>
#include <stdexcept>

class PmergeMe {
private:
    // Comparison functor for sorting pairs
    struct PairComparator {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.second < b.second;
        }
    };

public:
    PmergeMe();
    ~PmergeMe();

    void processInput(int argc, char** argv);

private:
    // Sorting with std::vector
    void sortWithVector(std::vector<int>& data);

    // Sorting with std::list
    void sortWithList(std::list<int>& data);

    // Ford-Johnson (Merge-Insertion) Sort implementation for vector
    void mergeInsertionSortVector(std::vector<int>& arr);
    void insertElementVector(std::vector<int>& arr, int val, int left, int right);

    // Ford-Johnson (Merge-Insertion) Sort implementation for list
    void mergeInsertionSortList(std::list<int>& arr);
    void insertElementList(std::list<int>& arr, std::list<int>::iterator left, std::list<int>::iterator right, int val);

    // Helper functions
    bool isPositiveInteger(const std::string& s);
    void printBefore(const std::vector<int>& data);
    void printAfter(const std::vector<int>& data);
    void printTime(const std::string& containerType, clock_t start, clock_t end, size_t n);
};

#endif