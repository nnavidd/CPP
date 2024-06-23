/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:32:18 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/23 19:25:42 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int main () {
	std::cout << RED "----------int arr----------" RESET << std::endl;
	{
		int arr[] = {1, 2, 3, 4, 5};

		std::size_t size = sizeof(arr) / sizeof(arr[0]);
		printMemberArray(arr, size, "Befor");
		// calling incFunc function
		iter(arr, size, incFunc<int>);
		printMemberArray(arr, size, "After");
	}
	std::cout << RED "----------char arr----------" RESET << std::endl;
	{
		char arr[] = {'a', 'b', 'c', 'd', 'e'};
		
		std::size_t size = sizeof(arr) / sizeof(arr[0]);
		printMemberArray(arr, size, "Befor");
		// calling incFunc function
		iter(arr, size, incFunc<char>);
		printMemberArray(arr, size, "Befor");
	}
	std::cout << RED "----------string arr----------" RESET << std::endl;
	{
		std::string arr[] = {"Hello", "world!,", "today", "is a", "good day!"};
		
		std::size_t size = sizeof(arr) / sizeof(arr[0]);
		// calling incFunc function
        iter(arr, size, printStringArray<std::string>);
		std::cout << std::endl;
	}

	return (0);
}