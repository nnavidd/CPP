/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:14 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/13 17:58:59 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>
#include <stdexcept>
#include <functional> // For std::bind

class PmergeMe {
	private:
		std::vector<int>	_vecData;
		std::deque<int>		_dequeData;

		// template < typename T >
		// void insertIntoSortedContainer( T & sortedContainer, typename T::value_type num );

		std::vector<size_t> generateJacobsthalIndices(size_t size);

		PmergeMe( PmergeMe const & );
		PmergeMe & operator=( PmergeMe const & );

	public:
		PmergeMe();
		~PmergeMe();

		void setVectorData( int const value );
		void setDequeData( int const value );

		void reserveInput(size_t size);

		std::vector<int> const & getVectorData() const;
		std::deque<int> const & getDequeData() const;

		void fordJohnsonSortVector(std::vector<int>& container);
		void fordJohnsonSortDeque(std::deque<int>& container);

		// template <typename T>
		// void fordJohnsonSortMethod( T & container );
};


// template <typename T>
// void PmergeMe::insertIntoSortedContainer( T & sortedContainer, typename T::value_type num ) {
//     auto position = std::lower_bound(sortedContainer.begin(), sortedContainer.end(), num);
//     sortedContainer.insert(position, num);
// }


// template <typename T>
// void PmergeMe::fordJohnsonSortMethod( T & container ) {
//     if (container.size() <= 1) return;

//     T biggerNumberGroup, smallerNumberGroup;

// 	if constexpr (std::is_same<T, std::vector<typename T::value_type>>::value) {
// 		biggerNumberGroup.reserve(container.size());
// 		smallerNumberGroup.reserve(container.size() / 2);
// 	}

//     // Pair numbers up and separate them into two groups of smaller and larger numbers
//     auto it = container.begin();
//     while (it != container.end()) {

//         auto next = std::next(it);

//         if (next == container.end()) {
//             biggerNumberGroup.push_back(*it);
//             break;
//         }

//         if (*it < *next) {
//             smallerNumberGroup.push_back(*it);
//             biggerNumberGroup.push_back(*next);
//         } else {
//             smallerNumberGroup.push_back(*next);
//             biggerNumberGroup.push_back(*it);
//         }
//         std::advance(it, 2);
//     }

//     // Sort the larger group using Ford-Johnson method
//     fordJohnsonSortMethod(biggerNumberGroup);

// 	// Use the Jacobsthal sequence to determine the insertion order
// 	std::vector<size_t> insertionOrder = generateJacobsthalIndices(smallerNumberGroup.size());

// 	///////////////////////////////////////
// 	std::vector<size_t> insertionOrders = generateJacobsthalIndices(10);
// 	std::cout << "insertionOrders: ";
// 	for (auto i : insertionOrders) {
// 		std::cout << i << ", ";	
// 	} std::cout << std::endl;
// 	// Insert the smaller numbers into the sorted Larger group at the appropriate possitions according to the Jacobsthal sequence
// 	for (size_t idx : insertionOrder) {
// 		insertIntoSortedContainer(biggerNumberGroup, smallerNumberGroup[idx]);
// 	}
	
// 	// Clear the original container and copy the sorted elements back
//     container = biggerNumberGroup;
// }
	

// 	// if (insertionOrder.size() > 0 && !smallerNumberGroup.empty()) {
// 	// 	std::cout << "smallerNumberGroup: ";
// 	// 	for (auto i : smallerNumberGroup) {
// 	// 		std::cout << i << " ";
		
// 	// 	} std::cout << std::endl;
// 	// }
// 	///////////////////////////////////////

#endif // PMERGEME_HPP