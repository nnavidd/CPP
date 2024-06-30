/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:50:37 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/30 12:18:06 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/Span.hpp"

// Default constructor
Span::Span( void ) : _maxSize(0) {}

// Constructor with size
Span::Span( unsigned int N ) : _maxSize(N) {}

// Copy constructor
Span::Span( Span const & other ) : _maxSize(other._maxSize), _vec(other._vec) {}

// Copy assignment operator
Span& Span::operator=( Span const & other ) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _vec = other._vec;
    }
    return (*this);
}

// Destructor
Span::~Span( void ) {}

// Adds a single number to the Span
void Span::addNumber( int number ) {
    if (_vec.size() >= _maxSize) {
        throw std::out_of_range( ORG "Cannot add more numbers, span is full." RESET);
    }
    _vec.push_back(number);
}

int Span::shortestSpan() const {
    if (_vec.size() < 2) {
        throw std::logic_error( ORG "No span can be found, not enough numbers to find a span." RESET);
    }

    std::vector<int> sortedVec(_vec);
    std::sort(sortedVec.begin(), sortedVec.end());

    int shortestInt = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sortedVec.size() - 1; ++i) {
        int span = sortedVec[i + 1] - sortedVec[i];
        if (span < shortestInt) {
            shortestInt = span;
        }
    }
    return (shortestInt);
}

int Span::longestSpan() const {
    if (_vec.size() < 2) {
        throw std::logic_error( ORG "No span can be found, not enough numbers to find a span." RESET);
    }

    int minNumber = *std::min_element(_vec.begin(), _vec.end());
    int maxNumber = *std::max_element(_vec.begin(), _vec.end());
    return (maxNumber - minNumber);
}

unsigned int Span::size() const {
    return (_vec.size());
}

void Span::showContainerElements( int begin, int end ) const {
    if (end == -1)
        end = _vec.size();
    if (begin == -1)
        begin = _vec[0];
    // Check if the range is valid
    if (begin < 0 || end > static_cast<int>(_vec.size()) || begin > end) {
        throw std::out_of_range("Invalid range");
    }

    std::vector<int>::const_iterator itr = _vec.begin() + begin;
    std::cout << "Container: { ";
    for (; itr != _vec.begin() + end; ++itr) {
        std::cout << *itr;
        if (itr + 1 != _vec.begin() + end) {
            std::cout << " , ";
        }
    }
    std::cout << " }" << std::endl;
}