/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNExceptions.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:19:31 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/12 13:50:20 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// RPNExceptions.hpp
#ifndef RPN_EXCEPTIONS_HPP
#define RPN_EXCEPTIONS_HPP

#include "RPNException.hpp"
#include <exception>
#include <string>

// Specific exception classes
class InvalidNumberException : public RPNException {
public:
    InvalidNumberException(const std::string& token) : 
        RPNException("Invalid number: " RESET + token) {}
};

class NumberTooLargeException : public RPNException {
public:
    NumberTooLargeException(const std::string& token) : 
        RPNException("Number too large (must be < 10): " RESET + token) {}
};

class InvalidTokenException : public RPNException {
public:
    InvalidTokenException(const std::string& token) : 
        RPNException("Invalid token: " RESET + token) {}
};

class InvalidOperatorException : public RPNException {
public:
    InvalidOperatorException(const std::string& op) : 
        RPNException("Invalid operator: " RESET + op) {}
};

class NotEnoughOperandsException : public RPNException {
public:
    NotEnoughOperandsException() : 
        RPNException("Not enough operands for operation") {}
};

class DivisionByZeroException : public RPNException {
public:
    DivisionByZeroException() : 
        RPNException("Division by zero") {}
};

class InvalidExpressionException : public RPNException {
public:
    InvalidExpressionException() : 
        RPNException("Invalid expression - check operand/operator count") {}
};

#endif // RPN_EXCEPTIONS_HPP