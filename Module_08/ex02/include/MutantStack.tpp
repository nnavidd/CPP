/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:20:59 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/30 15:52:53 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "../include/MutantStack.hpp"

// Constructors
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

// Assignment operator
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

// Iterator functions
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}


template <typename T>
void MutantStack<T>::showContainerElements( int begin, int end ) const {
	if (end == std::numeric_limits<int>::min()) {
		if( begin > 0) {
			end = begin;
			begin = 0;
		} else
			end = this->size();
	}
	if (begin == std::numeric_limits<int>::min())
		begin = 0;
	if (begin < 0 || end > static_cast<int>(this->size()) || begin > end) {
		throw std::out_of_range( ORG "Invalid range" RESET);
	}
	if (begin > 0)
		begin--;
	typename std::deque<T>::const_iterator itr = this->begin() + begin;
	typename std::deque<T>::const_iterator endItr = this->begin() + end;
	std::cout << GREEN "Container elements: " RED "{";
	for (; itr != endItr; ++itr) {
		std::cout << ORG << *itr;
		if (itr + 1 != endItr) {
			std::cout << RED ", ";
		}
	}
	std::cout << RED "}" RESET<< std::endl;
}

#endif // MUTANTSTACK_TPP
