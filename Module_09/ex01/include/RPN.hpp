/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:39:59 by nnavidd           #+#    #+#             */
/*   Updated: 2025/04/28 09:07:16 by nnabaeei         ###   ########.fr       */
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

class RPN {
	private:
		bool isOperator( std::string const &token );

		bool isNumber( std::string const &token );

		// Helper function to apply an operator to two operands
		int applyOperator( std::string const &op, int a, int b );
		
		// Helper function to convert string to int
		int stringToInt( std::string const & str );

		// Copy Constructor
		RPN( RPN const & );
		
		// Copy Assignment Operator
		RPN& operator=( RPN const & );
	
	public:
		// Default Constructor
		RPN();
			
		// Destructor
		~RPN();

		int evaluate( std::string const & expression );
    
};

#endif
