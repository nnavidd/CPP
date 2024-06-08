/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:48:28 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/08 11:56:38 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int ac, char **av)
{
    Harl		harl;
	std::string	level;

	do
	{
		std::cout << BLUE "Insert Desired Harl Level:" RESET"{" GREEN"DEBUG" RESET
		"," GREEN" INFO" RESET"," GREEN" WARNING" RESET"," GREEN" ERROR" RESET"}" << std::endl;
		std::getline(std::cin, level);
		harl.complian(level);
		std::cout << std::endl;
	} while (ac && av[0] && level.compare("exit"));
    return (0);
}