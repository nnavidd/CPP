/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:44:57 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/04/29 20:20:29 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( PmergeMe const & other )
    : _vecData(other._vecData), _dequeData(other._dequeData) {}

PmergeMe& PmergeMe::operator=( PmergeMe const & other ) {
    if (this != &other) {
        _vecData = other._vecData;
        _dequeData = other._dequeData;
    }
    return *this;
}

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
