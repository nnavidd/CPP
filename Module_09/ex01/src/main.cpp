/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:18:41 by nnavidd           #+#    #+#             */
/*   Updated: 2025/05/22 16:16:54 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/RPN.hpp"
#include <iostream>
#include <list>
#include <string>

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"


#include <string>
#include <iomanip>
#include <sstream>
#include <limits>

// Converts __int128 to a string, optionally in scientific notation if > LLONG_MAX
std::string formatInt128(__int128 value, int precision = 5) {
    const __int128 LLONG_MAX_128 = static_cast<__int128>(std::numeric_limits<long long>::max());

    if (value <= LLONG_MAX_128 && value >= -LLONG_MAX_128) {
        // Can safely cast to long long and print normally
        std::ostringstream oss;
        oss << static_cast<long long>(value);
        return oss.str();
    }

    // Convert to scientific notation if too big
    bool isNegative = value < 0;
    if (isNegative) value = -value;

    // Convert to string manually
    std::string digits;
    __int128 tmp = value;
    while (tmp > 0) {
        digits = char('0' + tmp % 10) + digits;
        tmp /= 10;
    }

    std::ostringstream oss;
    if (isNegative) oss << "-";
    oss << digits[0]; // first digit

    if (precision > 0 && digits.length() > 1) {
        oss << "." << digits.substr(1, precision);
    }

    oss << "e+" << (digits.length() - 1);
    return oss.str();
}



// Helper function to process and display a single expression
int processExpression(const std::string& expression) {
    RPN rpn;
    try {
        __int128 result = rpn.evaluate(expression);
        std::cout << CYAN "The result of: \"" ORG << expression << CYAN "\"" << CYAN " is => " GREEN << formatInt128(result) << RESET << std::endl;
		return (0);
    } catch (const RPNException& e) {
        std::cerr << CYAN "The result of: \"" ORG << expression << CYAN "\"" << CYAN " is => " RED " Error: " << ORG << e.what() << RESET << std::endl;
		return (1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        if (argc == 1) {
			// Test cases
            std::list<std::string> li;
            li.push_back("8 9 * 9 - 9 - 9 - 4 - 1 +");
            li.push_back("8 9 * 9 - 9 - 9 - 4 - 10 +"); // Number >= 10
            li.push_back("7 7 * 7 -");
            li.push_back("7 7 * 7 "); // Invalid expression: missing operator
            li.push_back("7 7 * 0 /"); // Invalid expression: division by zero
            li.push_back("1 2 * 2 / 2 * 2 4 - +");
            li.push_back("1 2 * 2e / 2 * 2 4 - +"); // Invalid expression: non-integer
            li.push_back("(1 + 1)"); // Invalid expression
            li.push_back("1 + +"); // Invalid expression: not enough operands
            li.push_back("123"); // Number >= 10
            li.push_back(""); // Empty expression
			li.push_back("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -");
			li.push_back("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /");
			li.push_back("2 5 * 4 + 3 2 * 1 + /");
			li.push_back("4 4 + 6 2 * + 5 + 5 + 4 * 6 / 2 +");
			li.push_back("7 7 * -7 -");
			li.push_back("7 -7 * -7 -");
			li.push_back("7 7 * 7.4 -");
			li.push_back("asdfasf");
			li.push_back("4 4 + 6 2 * + 5 + 5 d 4 * 6 / 2 +");
			li.push_back("9 9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *9 *");
			li.push_back("9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *");
			li.push_back("2 2");
			li.push_back("2 / / /");
			li.push_back("9 9 * 9 *");
			li.push_back("11 2 +");

			for (const auto& testCase : li) {
                processExpression(testCase);
            }
            return (0);
        } else {
            std::cerr << RED "Error: " << ORG "Invalid number of arguments" << RESET << std::endl;
			std::cerr << GREEN "Usage: " << CYAN "./RPN \"expression\"" << RESET << std::endl;
            return (1);
        }
    }
	// Process the expression provided as argument
    	return (processExpression(argv[1]));
    return 0;
}

