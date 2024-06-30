/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:19:38 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/30 15:55:56 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <stack>
# include <deque>
# include <iterator>
# include <limits>
# include <iostream>
# include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	// Constructors
	MutantStack();
	MutantStack(const MutantStack<T> &other);
	virtual ~MutantStack();

	// Assignment operator
	MutantStack<T> &operator=(const MutantStack<T> &other);

	// Iterator types
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	// Iterator functions
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	void showContainerElements( int begin = std::numeric_limits<int>::min(),
			 int end = std::numeric_limits<int>::min()) const;

};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
