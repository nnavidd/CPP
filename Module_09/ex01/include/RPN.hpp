/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:39:59 by nnavidd           #+#    #+#             */
/*   Updated: 2025/05/12 15:51:25 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
#define RPN_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <sstream>
#include <stdexcept>
#include "RPNExceptions.hpp"

class RPN {
	private:
		std::stack<__int128> _stack;
		
		// Helper methods
		bool isOperator( std::string const &token ) const;
		bool isNumber( std::string const &token ) const;
		__int128 applyOperator( std::string const &op, __int128 a, __int128 b );		
		__int128 stringToInt( std::string const & str );

		// Copy Constructor
		RPN( RPN const & );
		
		// Copy Assignment Operator
		RPN& operator=( RPN const & );
	
	public:
		// Default Constructor
		RPN();
			
		// Destructor
		~RPN();

		// Main evaluation method
		__int128 evaluate( std::string const & expression );
    
};

#endif
