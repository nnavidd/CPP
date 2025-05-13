/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:44:46 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/13 17:44:38 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/PmergeMe.hpp"

template <typename T>
void showContainerElements( std::string const & msg, T const & container ) {
    std::cout << ORG << msg << RESET;
    for (auto const & element : container) {
        std::cout << GREEN << element << RESET << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T CopyContainerElements( T const & container ) {
	T copy;
	for (auto const & item : container) {
		copy.push_back(item);
	}
	return copy;
}

template <typename Container>
void testContainer( PmergeMe & sorter, Container & data, std::string const & containerName ) {

    std::cout << MAGENTA << "Testing with "  CYAN << containerName << ":"  RESET << std::endl;

    // Create a copy of the data for displaying the "Before" state
	auto beforeSort = CopyContainerElements(data);
    showContainerElements("Before: ", beforeSort);

	// Declare timing variables
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;

	// Call specific sorting function based on container type
    if constexpr (std::is_same<Container, std::vector<int>>::value) {
    	startTime = std::chrono::high_resolution_clock::now();	
        sorter.fordJohnsonSortVector(data);
    	endTime = std::chrono::high_resolution_clock::now();
    } else if constexpr (std::is_same<Container, std::deque<int>>::value) {
    	startTime = std::chrono::high_resolution_clock::now();
        sorter.fordJohnsonSortDeque(data);
    	endTime = std::chrono::high_resolution_clock::now();
    }

    // sorter.fordJohnsonSortMethod(data); // Assuming your sorting function in PmergeMe is named fordJohnsonSortMethod and can take different container types

    // Create a copy of the sorted data for displaying the "After" state
    auto afterSort = CopyContainerElements(data);
    showContainerElements("After: ", afterSort);

    std::chrono::duration<double, std::micro> elapsedTime = endTime - startTime;
    std::cout <<  MAGENTA "Time to process a range of " ORG << data.size()
              << MAGENTA " elements with " CYAN << containerName << ": " GREEN << elapsedTime.count() << ORG " us"  RESET << std::endl;
}


bool isNumber(const std::string& str) {
    if (str.empty()) return (false);
    
	size_t i = 0;
    if (str[0] == '-') {
        if (str.size() == 1) return (false); // "-" alone is not a number
        i = 1;
    }

    for (; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) 
			return (false);
    }
    return (true);
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
		sorter.reserveInput(argc - 1);
        loadInput(argc, argv, sorter);

        auto vecData = sorter.getVectorData();
        auto dequeData = sorter.getDequeData();

        // std::vector<std::pair<std::string, std::function<void()>>> tests;
        // tests.push_back({"std::vector", [&]() { testContainer(sorter, vecData, "std::vector"); }});
        // tests.push_back({"std::deque", [&]() { testContainer(sorter, dequeData, "std::deque"); }});

        // for (auto const & test : tests) {
        //     test.second(); // Execute the test function
		// 	std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;
        // }

		testContainer(sorter, vecData, "std::vector");
        std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;

        testContainer(sorter, dequeData, "std::deque");
        std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;



    } catch (const std::exception& e) {
        std::cerr << RED "Error: " << ORG << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
