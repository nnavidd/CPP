#include "../include/PmergeMe.hpp"


// template <typename T>
// void displayData(const std::string& message, const T& container) {
//     std::cout << message;
//     for (const auto& val : container) {
//         std::cout << val << " ";
//     }
//     std::cout << std::endl;
// }

// int main(int argc, char* argv[]) {
//     if (argc < 2) {
//         std::cerr << "Usage: ./PmergeMe <positive integers>" << std::endl;
//         return 1;
//     }

//     try {
//         PmergeMe sorter;

//         sorter.loadInput(argc, argv);

//         std::cout << "Testing with std::vector:" << std::endl;
//         auto vecData = sorter.getVectorData();
//         displayData("Before: ", vecData);

//         auto startVec = std::chrono::high_resolution_clock::now();
//         sorter.fordJohnsonSort(vecData);
//         auto endVec = std::chrono::high_resolution_clock::now();
//         displayData("After: ", vecData);
//         std::chrono::duration<double, std::micro> elapsedVec = endVec - startVec;
//         std::cout << "Time to process a range of " << vecData.size()
//                   << " elements with std::vector: " << elapsedVec.count() << " us\n" << std::endl;

//         std::cout << "Testing with std::list:" << std::endl;
//         auto listData = sorter.getListData();
//         displayData("Before: ", std::vector<int>(listData.begin(), listData.end()));

//         auto startList = std::chrono::high_resolution_clock::now();
//         sorter.fordJohnsonSort(listData);
//         auto endList = std::chrono::high_resolution_clock::now();
//         displayData("After: ", std::vector<int>(listData.begin(), listData.end()));
//         std::chrono::duration<double, std::micro> elapsedList = endList - startList;
//         std::cout << "Time to process a range of " << listData.size()
//                   << " elements with std::list: " << elapsedList.count() << " us\n" << std::endl;

//         std::cout << "Testing with std::deque:" << std::endl;
//         std::deque<int> dequeData(sorter.getVectorData().begin(), sorter.getVectorData().end());
//         displayData("Before: ", std::vector<int>(dequeData.begin(), dequeData.end()));

//         auto startDeque = std::chrono::high_resolution_clock::now();
//         sorter.fordJohnsonSort(dequeData);
//         auto endDeque = std::chrono::high_resolution_clock::now();
//         displayData("After: ", std::vector<int>(dequeData.begin(), dequeData.end()));
//         std::chrono::duration<double, std::micro> elapsedDeque = endDeque - startDeque;
//         std::cout << "Time to process a range of " << dequeData.size()
//                   << " elements with std::deque: " << elapsedDeque.count() << " us\n" << std::endl;

//     } catch (const std::exception& e) {
//         std::cerr << e.what() << std::endl;
//         return 1;
//     }

//     return 0;
// }



// template <typename T>
void displayData(const std::string& message, const std::vector<int> & container) {
    std::cout << message;
    for (const auto& val : container) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void testContainer(PmergeMe& sorter, Container& data, const std::string& containerName) {
    std::cout << "Testing with " << containerName << ":" << std::endl;

    // Create a copy of the data for displaying the "Before" state
    std::vector<int> beforeData;
    for (const auto& item : data) {
        beforeData.push_back(item);
    }
    displayData("Before: ", beforeData);

    auto start = std::chrono::high_resolution_clock::now();
    sorter.fordJohnsonSort(data); // Assuming your sorting function in PmergeMe is named fordJohnsonSort and can take different container types
    auto end = std::chrono::high_resolution_clock::now();

    // Create a copy of the sorted data for displaying the "After" state
    std::vector<int> afterData;
    for (const auto& item : data) {
        afterData.push_back(item);
    }
    displayData("After: ", afterData);

    std::chrono::duration<double, std::micro> elapsed = end - start;
    std::cout << "Time to process a range of " << data.size()
              << " elements with " << containerName << ": " << elapsed.count() << " us\n" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <positive integers>" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.loadInput(argc, argv);

        auto vecData = sorter.getVectorData();
        auto listData = sorter.getListData();
        std::deque<int> dequeData(vecData.begin(), vecData.end());

        std::vector<std::pair<std::string, std::function<void()>>> tests;
        tests.push_back({"std::vector", [&]() { testContainer(sorter, vecData, "std::vector"); }});
        tests.push_back({"std::list", [&]() { testContainer(sorter, listData, "std::list"); }});
        tests.push_back({"std::deque", [&]() { testContainer(sorter, dequeData, "std::deque"); }});

        for (const auto& test : tests) {
            test.second(); // Execute the test function
        }

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}