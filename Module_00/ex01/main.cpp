/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:28:26 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/27 09:28:28 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

int main (int ac, char **av)
{
	std::string	input;
	PhoneBook   pb;

	(void)av;
	if (ac == 1 && av[0]){
		while (true)
		{
			std::cout << ORG "Plseas Select One Of The Ahead Commands: " GREEN "ADD" RESET " | " GREEN "SEARCH" RESET " | " GREEN "EXIT" RESET << std::endl << std::flush;
			std::getline(std::cin, input);
			if (!std::cin.fail() && (input == "ADD")){
				pb.set_Contact();
			}
			else if (!std::cin.fail() && (input == "SEARCH")){
				pb.get_Contact();
			}
			else if (!std::cin.fail() && (input == "EXIT"))
				break;
			std::cin.clear();
		}
		std::cout << RED "-----The Phonebook Is Closed!-----" RESET << std::endl;
	}
	return (0);
}
