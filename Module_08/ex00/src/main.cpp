/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:56:36 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/30 00:20:56 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.h"

int main() {
	{
		std::cout << "----- Passing " CYAN "List" RESET" container to the funciton -----" RESET<< std::endl;
		std::list<int>	li;
	
		for (int i = 0; i < 31; i++)
			li.push_back(i * 10);

		try {
			std::list<int>::iterator li_check = easyfind(li, 20);
			std::cout << GREEN "fonud value " ORG"20" GREEN " in the " CYAN "LIST" GREEN" container at position: " CYAN
			<< std::distance(li.begin(), li_check) << RESET << std::endl;

			std::cout << RED "---------- exception ----------" RESET << std::endl;
			li_check = easyfind(li, 21);
			std::cout << GREEN "fonud value " ORG"20" GREEN " at position: " MAGENTA
			<< std::distance(li.begin(), li_check) << RESET << std::endl;
			
		} catch (Error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n----- Passing " CYAN "VECTOR" RESET" container to the funciton -----" << std::endl;
		std::vector<int>	ve;
	
		for (int i = 0; i < 31; i++)
			ve.push_back(i * 10);

		try {
			std::vector<int>::iterator ve_check = easyfind(ve, 30);
			std::cout << GREEN "fonud value " ORG"30" GREEN " in the " CYAN "VECTOR" GREEN" container at position: " CYAN
			<< std::distance(ve.begin(), ve_check) << RESET << std::endl;

			std::cout << RED "---------- exception ----------" RESET << std::endl;
			ve_check = easyfind(ve, 4);
			std::cout << GREEN "fonud value " ORG"30" GREEN " at position: " MAGENTA
			<< std::distance(ve.begin(), ve_check) << RESET << std::endl;
			
		} catch (Error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n----- Passing an " CYAN "Array" RESET" container to the funciton -----" << std::endl;
		int	arr[] = {10, 20, 30, 40};
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
		try {
			std::vector<int>::iterator ve_check = easyfind(vec, 10);
			std::cout << GREEN "fonud value " ORG"10" GREEN " in the " CYAN "VECTOR (created of an Array)" GREEN" container at position: " CYAN
			<< std::distance(vec.begin(), ve_check) << RESET << std::endl;

			std::cout << RED "---------- exception ----------" RESET << std::endl;
			ve_check = easyfind(vec, 1);
			std::cout << GREEN "fonud value " ORG"10" GREEN " at position: " MAGENTA
			<< std::distance(vec.begin(), ve_check) << RESET << std::endl;
			
		} catch (Error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}