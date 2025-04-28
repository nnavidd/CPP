/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:18:41 by nnavidd           #+#    #+#             */
/*   Updated: 2025/04/28 09:18:29 by nnabaeei         ###   ########.fr       */
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

int main(int argc, char *argv[]) {
    if (argc != 2) {
        if (argc == 1) {
            std::list<std::string> li;
            li.push_back("8 9 * 9 - 9 - 9 - 4 - 1 +");
            li.push_back("8 9 * 9 - 9 - 9 - 4 - 10 +");
            li.push_back("7 7 * 7 -");
            li.push_back("7 7 * 7 "); // Invalid expression: missing operator
            li.push_back("7 7 * 0 /"); // Invalid expression: division by zero
            li.push_back("1 2 * 2 / 2 * 2 4 - +");
            li.push_back("1 2 * 2e / 2 * 2 4 - +"); // Invalid expression: non-integer
            li.push_back("(1 + 1)"); // Invalid expression

            for (std::list<std::string>::iterator i = li.begin(); i != li.end(); ++i) {
                RPN rpn;
                try {
                    int result = rpn.evaluate(*i);
                    std::cout << CYAN "The result of:\"" ORG<< *i <<CYAN "\"is => " << GREEN << result << RESET << std::endl;
                } catch (const std::exception &e) {
					std::cout << CYAN "The result of:\"" ORG<< *i <<CYAN "\"is => ";
                    std::cerr << RED "Error: " << ORG << e.what() << RESET << std::endl;
                    // return 1;
					continue;
                }
            }
            return 0;
        } else {
            std::cerr << RED "Error: " << ORG "Invalid number of arguments" << RESET << std::endl;
            return 1;
        }
    }

    RPN rpn;

    try {
        int result = rpn.evaluate(argv[1]);
        std::cout << CYAN "The result of:\"" ORG<< argv[1] <<CYAN "\"is => " << GREEN << result << RESET << std::endl;
    } catch (const std::exception &e) {
        std::cerr << RED "Error: " << ORG << e.what() << RESET << std::endl;
        return 1;
    }

    return 0;
}
