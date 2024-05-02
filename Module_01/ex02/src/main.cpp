/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:26:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/02 13:36:32 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Header.hpp"

int main ()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << ORG "The memory address of the string variable:\t" RESET GREEN << &string << std::endl
				<< ORG "The memory address held by stringPTR:\t\t" RESET GREEN << stringPTR << std::endl
				<< ORG "The memory address held by stringREF:\t\t" RESET GREEN << &stringREF << std::endl << std::endl
				<< ORG "The value of the string variable:\t\t" RESET GREEN << string << std::endl
				<< ORG "The value pointed to by stringPTR:\t\t" RESET GREEN << *stringPTR << std::endl
				<< ORG "The value pointed to by stringREF:\t\t" RESET GREEN << stringREF << std::endl;
    return (0);
}