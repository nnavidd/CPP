/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:56:00 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/24 09:44:27 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <iostream>
# include <string>
# include <exception>

template <typename T>
class Array{
	private:
		unsigned int	_size;
		T				*_arr;
	public:
		Array( void );
		Array( Array const & );
		Array & operator=( Array const & );
		~Array( void );

		Array( unsigned int n );
		T & operator[]( std::size_t const index );
		T const & operator[]( std::size_t const index ) const;
		unsigned int size();

		class ExceptAssignError: public std::exception {
			virtual const char* what() const throw();
		};
		class ExceptReturnError: public std::exception {
			virtual const char* what() const throw();
		};
};


# include "Array.tpp"

#endif