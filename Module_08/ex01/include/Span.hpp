/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 01:49:00 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/30 14:01:58 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <iostream>
# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <limits>
# include <time.h>
# include <cstdio>
# include <stdlib.h>

class Span {
	private:
		unsigned int        _maxSize;
		std::vector<int>    _vec;

	public:
		// Constructors
		Span( void );
		Span( unsigned int N );

		// Copy constructor
		Span( Span const & );

		// Assignment operator
		Span & operator=( Span const & );

		// Destructor
		~Span( void );

		// Member functions
		void addNumber( int number );

		template <typename Iterator>
		void addNumbers( Iterator begin, Iterator end );

		int shortestSpan() const;
		int longestSpan() const;

		// Size function
		unsigned int size() const;

		void showContainerElements( int begin = std::numeric_limits<int>::min(), 
					int end = std::numeric_limits<int>::min() ) const;

};

# include "Span.tpp"

#endif // SPAN_HPP
