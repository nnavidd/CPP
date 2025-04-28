#include "../include/PmergeMe.hpp"
#include <sstream>
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositiveInteger(const std::string& s) {
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '+')) || (s[0] == '+' && s.length() == 1)) {
        return false;
    }
    std::string::const_iterator it = s.begin() + (s[0] == '+' ? 1 : 0);
    while (it != s.end() && isdigit(*it)) {
        ++it;
    }
    return it == s.end();
}

void PmergeMe::processInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return;
    }

    std::vector<int> vectorData;
    std::list<int> listData;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error: Invalid input '" << arg << "'. Please provide positive integers only." << std::endl;
            return;
        }
        std::stringstream ss(arg);
        int num;
        ss >> num;
        vectorData.push_back(num);
        listData.push_back(num);
    }

    if (vectorData.size() < 2) {
        printBefore(vectorData);
        printAfter(vectorData);
        std::cout << "Time to process a range of " << vectorData.size() << " element(s) with std::vector : 0.00000 us" << std::endl;
        std::cout << "Time to process a range of " << listData.size() << " element(s) with std::list : 0.00000 us" << std::endl;
        return;
    }

    printBefore(vectorData);

    // Sort with std::vector
    std::vector<int> sortedVectorData = vectorData;
    clock_t startVector = clock();
    sortWithVector(sortedVectorData);
    clock_t endVector = clock();

    printAfter(sortedVectorData);
    printTime("std::vector", startVector, endVector, vectorData.size());

    // Sort with std::list
    std::list<int> sortedListData = listData;
    clock_t startList = clock();
    sortWithList(sortedListData);
    clock_t endList = clock();

    std::vector<int> sortedVectorFromList(sortedListData.begin(), sortedListData.end());
    printTime("std::list", startList, endList, listData.size());
}

void PmergeMe::sortWithVector(std::vector<int>& data) {
    mergeInsertionSortVector(data);
}

void PmergeMe::sortWithList(std::list<int>& data) {
    mergeInsertionSortList(data);
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    std::vector<std::pair<int, int> > pairs;
    for (int i = 0; i < n / 2; ++i) {
        if (arr[2 * i] > arr[2 * i + 1]) {
            pairs.push_back(std::make_pair(arr[2 * i + 1], arr[2 * i]));
        } else {
            pairs.push_back(std::make_pair(arr[2 * i], arr[2 * i + 1]));
        }
    }
    if (n % 2 != 0) {
        pairs.push_back(std::make_pair(arr[n - 1], -1)); // Mark single element
    }

    std::vector<int> mainChain;
    std::vector<int> pending;

    // Sort pairs based on the larger element
    std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    for (const auto& p : pairs) {
        mainChain.push_back(p.second);
        if (p.first != -1) {
            pending.push_back(p.first);
        }
    }

    // Insert pending elements into the main chain using binary insertion
    for (int val : pending) {
        insertElementVector(mainChain, val, 0, mainChain.size() - 1);
    }

    arr = mainChain;
}

void PmergeMe::insertElementVector(std::vector<int>& arr, int val, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (val < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    arr.insert(arr.begin() + left, val);
}

void PmergeMe::mergeInsertionSortList(std::list<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    std::list<std::pair<int, int> > pairs;
    std::list<int>::iterator it = arr.begin();
    while (std::distance(it, arr.end()) > 1) {
        int first = *it;
        ++it;
        int second = *it;
        ++it;
        if (first > second) {
            pairs.push_back(std::make_pair(second, first));
        } else {
            pairs.push_back(std::make_pair(first, second));
        }
    }
    if (n % 2 != 0) {
        pairs.push_back(std::make_pair(*it, -1)); // Mark single element
    }

    std::list<int> mainChain;
    std::list<int> pending;

    // Sort pairs based on the larger element
    pairs.sort([](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    });

    for (const auto& p : pairs) {
        mainChain.push_back(p.second);
        if (p.first != -1) {
            pending.push_back(p.first);
        }
    }

    // Insert pending elements into the main chain using binary insertion
    for (int val : pending) {
        insertElementList(mainChain, val, mainChain.begin(), mainChain.end());
    }

    arr = mainChain;
}

void PmergeMe::insertElementList(std::list<int>& arr, int val, std::list<int>::iterator left, std::list<int>::iterator right) {
    std::list<int>::iterator it = left;
    while (it != right) {
        if (val < *it) {
            arr.insert(it, val);
            return;
        }
        ++it;
    }
    arr.insert(right, val);
}

void PmergeMe::printBefore(const std::vector<int>& data) {
    std::cout << "Before: ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << (i == data.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

void PmergeMe::printAfter(const std::vector<int>& data) {
    std::cout << "After: ";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << (i == data.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

void PmergeMe::printTime(const std::string& containerType, clock_t start, clock_t end, size_t n) {
    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << n << " elements with " << containerType << " : "
              << std::fixed << std::setprecision(5) << duration << " us" << std::endl;
}