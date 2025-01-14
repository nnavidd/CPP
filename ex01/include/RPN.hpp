/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:39:59 by nnavidd           #+#    #+#             */
/*   Updated: 2025/01/14 12:47:56 by nnavidd          ###   ########.fr       */
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
public:
    RPN();  // Default Constructor
    RPN( RPN const & );  // Copy Constructor
    RPN& operator=( RPN const & );  // Copy Assignment Operator
    ~RPN();  // Destructor

    int evaluate( std::string const & expression );
    
private:
    bool isOperator( std::string const &token );
    int applyOperator( std::string const &op, int a, int b );
    int stringToInt( std::string const & str );  // Helper function to convert string to int
};

#endif
