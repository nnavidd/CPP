/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:26:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/27 09:25:51 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main ()
{
	std::string		string = "HI THIS IS BRAIN";
	std::string		*stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The memory address of the string variable:\t" << &string << std::endl
				<< "The memory address held by stringPTR:\t\t" << stringPTR << std::endl
				<< "The memory address held by stringREF:\t\t" << &stringREF << std::endl << std::endl
				<< "The value of the string variable:\t\t" << string << std::endl
				<< "The value pointed to by stringPTR:\t\t" << *stringPTR << std::endl
				<< "The value pointed to by stringREF:\t\t" << stringREF << std::endl;
    return (0);
}