/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:39:46 by nnavidd           #+#    #+#             */
/*   Updated: 2025/05/12 15:54:05 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/RPN.hpp"

// Default Constructor
RPN::RPN() {}

// Copy Constructor
RPN::RPN( RPN const & other): _stack(other._stack) {}

// Copy Assignment Operator
RPN & RPN::operator=( RPN const & other ) {
    if (this != &other) {
        *this = other;
    }
    return (*this);
}

// Destructor
RPN::~RPN() {}

// Helper function to convert string to int
__int128 RPN::stringToInt(const std::string& str) {
    bool negative = false;
    size_t i = 0;
    if (str[i] == '-') {
        negative = true;
        ++i;
    }

    if (i == str.length()) {
        throw InvalidNumberException(str);
    }

    __int128 result = 0;
    for (; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            throw InvalidNumberException(str);
        }
        result = result * 10 + (str[i] - '0');
    }

    if (negative) result = -result;

    // Optional: still enforce number must be within -9 to 9 range
    if (result >= 10 || result <= -10) {
        throw NumberTooLargeException(str);
    }

    return (result);
}

// Helper function to check if a token is an operator
bool RPN::isOperator( std::string const & token ) const {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Helper function to apply an operator to two operands
__int128 RPN::applyOperator( std::string const & op, __int128 a, __int128 b ) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw DivisionByZeroException();
        }
        return (a / b);
    }
    throw InvalidOperatorException(op);
}

bool RPN::isNumber(const std::string& str) const {
    if (str.empty()) return (false);
    
	size_t i = 0;
    if (str[0] == '-') {
        if (str.size() == 1) return (false); // "-" alone is not a number
        i = 1;
    }

    for (; i < str.size(); ++i) {
        if (!std::isdigit(str[i])) 
			return (false);
    }
    return (true);
}

// The first number popped is the second operand, The second number popped is the first operand.
// Evaluate the RPN expression
__int128 RPN::evaluate(const std::string& expression) {
    // Clear stack from previous evaluations
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    // Process each token in the expression
    while (iss >> token) {
        if (isNumber(token)) {
            _stack.push(stringToInt(token));
        } else if (isOperator(token)) {
            if (_stack.size() < 2) {
                throw NotEnoughOperandsException();
            }
            __int128 b = _stack.top(); _stack.pop();
            __int128 a = _stack.top(); _stack.pop();
            __int128 result = applyOperator(token, a, b);
            _stack.push(result);
        } else {
            throw InvalidTokenException(token);
        }
    }
    
    // After processing all tokens, the stack should have exactly one value
    if (_stack.size() != 1) {
        throw InvalidExpressionException();
    }
    
    return (_stack.top());
}


