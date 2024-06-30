/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:19:38 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/07/01 00:33:19 by nnavidd          ###   ########.fr       */
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
		MutantStack( void );
		MutantStack( MutantStack<T> const &);
		virtual ~MutantStack();

		// Assignment operator
		MutantStack<T> & operator=( MutantStack<T> const & );

		// Iterator types
		typedef typename std::deque<T>::iterator				iterator;
		typedef typename std::deque<T>::const_iterator			const_iterator;
		typedef typename std::deque<T>::reverse_iterator		reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;

		// Iterator functions
		typename MutantStack<T>::iterator				begin();
		typename MutantStack<T>::const_iterator 		begin() const;
		typename MutantStack<T>::iterator 				end();
		typename MutantStack<T>::const_iterator 		end() const;
		typename MutantStack<T>::reverse_iterator		rbegin();
		typename MutantStack<T>::const_reverse_iterator rbegin() const;
		typename MutantStack<T>::reverse_iterator		rend();
		typename MutantStack<T>::const_reverse_iterator	rend() const;

		void showContainerElements( int begin = std::numeric_limits<int>::min(),
				int end = std::numeric_limits<int>::min()) const;

};

#include "MutantStack.tpp"

#endif // MUTANTSTACK_HPP
