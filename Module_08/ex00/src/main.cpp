/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:56:36 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/30 01:29:33 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.h"

int main() {
	{
		std::cout << "----- Passing " CYAN "List" RESET" container to the funciton -----" RESET<< std::endl;
		std::list<int>	li;
	
		for (int i = 0; i < 5; i++)
			li.push_back(i * 10);

		try {
			show_container(li);
			std::list<int>::iterator li_check = easyfind(li, 20);
			std::cout << GREEN "The value " ORG"20" GREEN " position in the " CYAN "LIST" GREEN" container is: " CYAN
			<< std::distance(li.begin(), li_check) << RESET << std::endl;

			std::cout << RED "---------- exception ----------" RESET << std::endl;
			li_check = easyfind(li, 21);
			std::cout << GREEN "The value " ORG"21" GREEN " position in the " CYAN "LIST" GREEN" container is: " CYAN
			<< std::distance(li.begin(), li_check) << RESET << std::endl;
			
		} catch (Error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n----- Passing " CYAN "VECTOR" RESET" container to the funciton -----" << std::endl;
		std::vector<int>	ve;
	
		for (int i = 0; i < 7; i++)
			ve.push_back(i * 2);

		try {
			show_container(ve);
			std::vector<int>::iterator ve_check = easyfind(ve, 6);
			std::cout << GREEN "The value " ORG"6" GREEN " position in the " CYAN "VECTOR" GREEN" container is: " CYAN
			<< std::distance(ve.begin(), ve_check) << RESET << std::endl;

			std::cout << RED "---------- exception ----------" RESET << std::endl;
			ve_check = easyfind(ve, 14);
			std::cout << GREEN "The value " ORG"14" GREEN " position in the " CYAN "VECTOR" GREEN" container is: " CYAN
			<< std::distance(ve.begin(), ve_check) << RESET << std::endl;
			
		} catch (Error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n----- Passing an " CYAN "Array" RESET" container to the funciton -----" << std::endl;
		int	arr[] = {11, 22, 33, 44, 55};
		std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	
		try {
			show_container(vec);
			std::vector<int>::iterator ve_check = easyfind(vec, 55);
			std::cout << GREEN "The value " ORG"55" GREEN " position in the " CYAN "VECTOR (created of an Array)" GREEN" container is: " CYAN
			<< std::distance(vec.begin(), ve_check) << RESET << std::endl;

			std::cout << RED "---------- exception ----------" RESET << std::endl;
			ve_check = easyfind(vec, 1);
			std::cout << GREEN "The value " ORG"1" GREEN " position in the " CYAN "VECTOR (created of an Array)" GREEN" container is: " CYAN
			<< std::distance(vec.begin(), ve_check) << RESET << std::endl;
			
		} catch (Error& e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}