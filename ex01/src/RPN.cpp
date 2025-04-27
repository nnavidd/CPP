/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:39:46 by nnavidd           #+#    #+#             */
/*   Updated: 2025/01/14 13:35:36 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/RPN.hpp"

// Default Constructor
RPN::RPN() {}

// Copy Constructor
RPN::RPN( RPN const & ) {}

// Copy Assignment Operator
RPN& RPN::operator=( RPN const & other ) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

// Destructor
RPN::~RPN() {}


// Evaluate the RPN expression
int RPN::evaluate( std::string const & expression ) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            stack.push(stringToInt(token));
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error(RED"Error" ORG ": Not enough operands" RESET);
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result = applyOperator(token, a, b);
            stack.push(result);
        } else {
            throw std::runtime_error(RED"Error" ORG ": Invalid token" RESET);
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error(RED"Error" ORG ": Invalid token" RESET);
    }

    return stack.top();
}


// Helper function to check if a token is an operator
bool RPN::isOperator( std::string const & token ) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}


// Helper function to apply an operator to two operands
int RPN::applyOperator( std::string const & op, int a, int b ) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) {
            throw std::runtime_error(RED"Error:" ORG " Division by zero" RESET);
        }
        return a / b;
    }
    throw std::runtime_error(RED"Error" ORG ": Invalid operator" RESET);
}

// Helper function to convert string to int
int RPN::stringToInt( std::string const & str ) {
    std::stringstream ss(str);
    int value;
    ss >> value;
    if (ss.fail()) {
        throw std::runtime_error("Error: Invalid number");
    }
    return value;
}
