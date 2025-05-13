/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:44:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/13 17:52:37 by nnabaeei         ###   ########.fr       */
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

void PmergeMe::fordJohnsonSortVector(std::vector<int>& container) {
    if (container.size() <= 1) return;

    std::vector<int> biggerGroup, smallerGroup;
    biggerGroup.reserve(container.size());
    smallerGroup.reserve(container.size() / 2);

    auto it = container.begin();
    while (it != container.end()) {
        auto next = std::next(it);
        if (next == container.end()) {
            biggerGroup.push_back(*it);
            break;
        }

        if (*it < *next) {
            smallerGroup.push_back(*it);
            biggerGroup.push_back(*next);
        } else {
            smallerGroup.push_back(*next);
            biggerGroup.push_back(*it);
        }
        std::advance(it, 2);
    }

    fordJohnsonSortVector(biggerGroup);

    std::vector<size_t> insertOrder = generateJacobsthalIndices(smallerGroup.size());
    for (size_t idx : insertOrder) {
        auto pos = std::lower_bound(biggerGroup.begin(), biggerGroup.end(), smallerGroup[idx]);
        biggerGroup.insert(pos, smallerGroup[idx]);
    }

    container = biggerGroup;
	// std::cout << "vector" << std::endl;
}


void PmergeMe::fordJohnsonSortDeque(std::deque<int>& container) {
    if (container.size() <= 1) return;

    std::deque<int> biggerGroup, smallerGroup;

    auto it = container.begin();
    while (it != container.end()) {
        auto next = std::next(it);
        if (next == container.end()) {
            biggerGroup.push_back(*it);
            break;
        }

        if (*it < *next) {
            smallerGroup.push_back(*it);
            biggerGroup.push_back(*next);
        } else {
            smallerGroup.push_back(*next);
            biggerGroup.push_back(*it);
        }
        std::advance(it, 2);
    }

    fordJohnsonSortDeque(biggerGroup);

    std::vector<size_t> insertOrder = generateJacobsthalIndices(smallerGroup.size());
    for (size_t idx : insertOrder) {
        auto pos = std::lower_bound(biggerGroup.begin(), biggerGroup.end(), smallerGroup[idx]);
        biggerGroup.insert(pos, smallerGroup[idx]);
    }

    container = biggerGroup;
	// std::cout << "deque" << std::endl;
}


std::vector<size_t> PmergeMe::generateJacobsthalIndices(size_t size) {
    std::vector<size_t> jacobIndices;
    if (size == 0) return jacobIndices;

    // Jacobsthal sequence: J(n) = J(n-1) + 2 * J(n-2)
    std::vector<size_t> jacobSeq = {0, 1, 3};
    while (jacobSeq.back() < size) {
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

    // Insert remaining indices in natural order
    for (size_t i = 0; i < size; ++i) {
        if (!used[i]) {
            jacobIndices.push_back(i);
        }
    }
	//  ////////////////////////////////////////////
	// std::cout << "JacobIndices: ";
	// for (auto i : jacobIndices) {
	// 	std::cout << i << " ";
	// } std::cout << std::endl;
	// /////////////////////////////////////////////////

    return jacobIndices;
}
