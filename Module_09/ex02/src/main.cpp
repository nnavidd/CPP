/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:44:46 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/04/29 22:03:49 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/PmergeMe.hpp"


void showContainerElements( std::string const & msg, std::vector<int> const & container ) {
    std::cout << ORG << msg << RESET;
    for (auto const & element : container) {
        std::cout << GREEN << element << RESET << " ";
    }
    std::cout << std::endl;
}


template <typename Container>
void testContainer( PmergeMe & sorter, Container & data, std::string const & containerName ) {
    std::cout << MAGENTA << "Testing with "  CYAN << containerName << ":"  RESET << std::endl;

    // Create a copy of the data for displaying the "Before" state
    std::vector<int> beforeSort;
    for (auto const & item : data) {
        beforeSort.push_back(item);
    }
    showContainerElements("Before: ", beforeSort);

    auto startTime = std::chrono::high_resolution_clock::now();
    sorter.fordJohnsonSortMethod(data); // Assuming your sorting function in PmergeMe is named fordJohnsonSortMethod and can take different container types
    auto endTime = std::chrono::high_resolution_clock::now();

    // Create a copy of the sorted data for displaying the "After" state
    std::vector<int> afterSort;
    for (auto const & item : data) {
        afterSort.push_back(item);
    }
    showContainerElements("After: ", afterSort);

    std::chrono::duration<double, std::micro> elapsedTime = endTime - startTime;
    std::cout <<  MAGENTA "Time to process a range of " ORG << data.size()
              << MAGENTA " elements with " CYAN << containerName << ": " GREEN << elapsedTime.count() << ORG " us"  RESET << std::endl;
}


bool isNumber( std::string const & str ) {
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
		if (!isdigit(*it)) {
			return false;
		}
	}
	return true;
}


void loadInput( int argc, char* argv[], PmergeMe & sorter ) {
    for (int i = 1; i < argc; ++i) {
		if (!isNumber(argv[i])) {
			throw std::invalid_argument("Invalid input. Only positive integers are allowed.");
		}
        int value = std::stoi(argv[i]);
        if (value < 0) {
            throw std::invalid_argument("Negative numbers are not allowed.");
        }
        sorter.setVectorData(value);
		sorter.setDequeData(value);
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << RED "Error: " << ORG "Invalid number of arguments" << RESET << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        loadInput(argc, argv, sorter);

        auto vecData = sorter.getVectorData();
        auto dequeData = sorter.getDequeData();

        std::vector<std::pair<std::string, std::function<void()>>> tests;
        tests.push_back({"std::vector", [&]() { testContainer(sorter, vecData, "std::vector"); }});
        tests.push_back({"std::deque", [&]() { testContainer(sorter, dequeData, "std::deque"); }});

        for (auto const & test : tests) {
            test.second(); // Execute the test function
			std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << RED "Error: " << ORG << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
