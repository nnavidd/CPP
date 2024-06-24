	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:11:37 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/23 19:21:52 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"

int main() {
	// Default constructor
	Array<int> arr1;
	std::cout << GREEN "arr1 (" MAGENTA "size" GREEN "): " ORG << arr1.size() << RESET << std::endl;

	// Constructor with size parameter
	Array<int> arr2(5);
	std::cout << GREEN "arr2 (" MAGENTA "size" GREEN "): " ORG << arr2.size() << RESET << std::endl;
	for (unsigned int i = 0; i < arr2.size(); ++i)
		std::cout << GREEN "arr2[" CYAN << i << GREEN "]: " ORG << arr2[i] << RESET << std::endl;

	// Copy constructor
	Array<int> arr3(arr2);
	std::cout << GREEN "arr3 size (" MAGENTA "after copy" GREEN "): " ORG << arr3.size() << RESET << std::endl;
	arr3[2] = 3;
	for (unsigned int i = 0; i < arr3.size(); ++i)
		std::cout << GREEN "arr3[" CYAN << i << GREEN "]: " ORG << arr3[i] << RESET << std::endl;

	// Assignment operator
	Array<int> arr4;
	arr4 = arr2;
	arr2[2] = 4;
	std::cout << GREEN "arr4 size (" MAGENTA "after assignment" GREEN "): " ORG << arr4.size() << RESET << std::endl;
	for (unsigned int i = 0; i < arr4.size(); ++i)
		std::cout << GREEN "arr4[" CYAN << i << GREEN "]: " ORG << arr4[i] << RESET << std::endl;

	// Modifying one array does not affect the other
	arr2[0] = 42;
	std::cout << GREEN "arr2[" CYAN "0" GREEN "] (" MAGENTA "after modification" GREEN "): " ORG << arr2[0] << RESET << std::endl;
	std::cout << GREEN "arr3[" CYAN "0" GREEN "] (" MAGENTA "after modification" GREEN "): " ORG << arr3[0] << RESET << std::endl;
	std::cout << GREEN "arr4[" CYAN "0" GREEN "] (" MAGENTA "after modification" GREEN "): " ORG << arr4[0] << RESET << std::endl;

	// Accessing out of bounds
	try {
		std::cout << arr2[10] << std::endl;
	} catch (std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << std::endl;
	}
	try {
		const Array<int> & constArr = arr4;
		std::cout << constArr[10] << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED "Exception: " << e.what() << std::endl;
	}

	return 0;
}

