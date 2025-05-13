/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:44:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/13 13:53:00 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe( PmergeMe const & other )
    : _vecData(other._vecData), _dequeData(other._dequeData) {}

// Copy assignment operator
PmergeMe& PmergeMe::operator=( PmergeMe const & other ) {
    if (this != &other) {
        _vecData = other._vecData;
        _dequeData = other._dequeData;
    }
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

void PmergeMe::setVectorData( int const value ) {
	_vecData.push_back(value);
}

void PmergeMe::setDequeData( int const value ) {
	_dequeData.push_back(value);
}

std::vector<int> const & PmergeMe::getVectorData() const {
    return _vecData;
}

std::deque<int> const & PmergeMe::getDequeData() const {
    return _dequeData;
}

void PmergeMe::reserveInput(size_t size) {
    _vecData.reserve(size);
    // _dequeData.resize(size);  // not needed for deque but safe
}


std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t size) {
    std::vector<size_t> jacobIndices;
    if (size == 0) return jacobIndices;

    // Jacobsthal sequence: J(n) = J(n-1) + 2 * J(n-2)
    std::vector<size_t> jacobSeq = {0, 1, 3};
    while (jacobSeq.back() < size) {
		// size_t next = jacobSeq[jacobSeq.size() - 1] + 2 * jacobSeq[jacobSeq.size() - 2];
		// if (next != 1 || jacobSeq.size() > 2)
        // 	jacobSeq.push_back(next);
        jacobSeq.push_back(jacobSeq[jacobSeq.size() - 1] + 2 * jacobSeq[jacobSeq.size() - 2]);
    }

    // Reverse Jacobsthal order insertion (skipping 0)
    std::vector<bool> used(size, false);
    for (size_t i = 1; i < jacobSeq.size(); ++i) {
        size_t idx = jacobSeq[i];
        if (idx < size && !used[idx]) {
            jacobIndices.push_back(idx);
            used[idx] = true;
        }
    }
	//  ////////////////////////////////////////////
	// std::cout << "Jacobsthal sequence: ";
	// for (auto i : jacobSeq) {
	// 	std::cout << i << " ";
	// } std::cout << std::endl;
	// /////////////////////////////////////////////////
	//  ////////////////////////////////////////////
	// std::cout << "JacobIndices: ";
	// for (auto i : jacobIndices) {
	// 	std::cout << i << " ";
	// } std::cout << std::endl;
	// /////////////////////////////////////////////////

    // Insert remaining indices in natural order
    for (size_t i = 0; i < size; ++i) {
        if (!used[i]) {
            jacobIndices.push_back(i);
        }
    }
	//  ////////////////////////////////////////////
	// std::cout << "Used: ";
	// for (size_t i = 0; i < used.size(); i++) {
	// 	std::cout << used[i] << " ";
	// } std::cout << std::endl;
	// /////////////////////////////////////////////////

    return jacobIndices;
}
