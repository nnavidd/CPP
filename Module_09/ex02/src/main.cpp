/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:44:46 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/22 15:32:45 by nnabaeei         ###   ########.fr       */
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
    try {
        PmergeMe sorter;
        if (argc < 2) {
            // Default test cases
            std::cout << ORG "No input provided. Running default tests with 10 and 100 elements..." RESET << std::endl;

            {
                // 10 number test
                std::vector<int> test10;
                for (int i = 10; i > 0; --i) test10.push_back(i);
                sorter.setVectorData(test10);
                sorter.setDequeData(std::deque<int>(test10.begin(), test10.end()));
    
                auto vecData10 = sorter.getVectorData();
                auto dequeData10 = sorter.getDequeData();
                
                testContainer(sorter, vecData10, "std::vector (10 elements)");
                std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;
                testContainer(sorter, dequeData10, "std::deque (10 elements)");;
                std::cout << MAGENTA << "========================================" << RESET << std::endl;    
            }
            {
                // 100 number test
                sorter.clearData();
                std::vector<int> test100;
                for (int i = 100; i > 0; --i) test100.push_back(i);
                sorter.setVectorData(test100);
                sorter.setDequeData(std::deque<int>(test100.begin(), test100.end()));
                
                auto vecData100 = sorter.getVectorData();
                auto dequeData100 = sorter.getDequeData();
                
                testContainer(sorter, vecData100, "std::vector (100 elements)");
                std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;
                testContainer(sorter, dequeData100, "std::deque (100 elements)");
                std::cout << MAGENTA << "----------------------------------------" << RESET << std::endl;
            }
            return 0;
        }

		sorter.reserveInput(argc - 1);
        loadInput(argc, argv, sorter);

        auto vecData = sorter.getVectorData();
        auto dequeData = sorter.getDequeData();

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