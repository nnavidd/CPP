/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:48:28 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/02 12:00:56 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

int main(int ac, char **av)
{
    Harl		harl;
	std::string	level;

	do
	{
		std::cout << BLUE "Insert Desired Harl Level: " << std::endl;
		std::getline(std::cin, level);
		// harl.complian(level);
		harl.HarlFilter(level);
	} while (ac && av[0] && level.compare("exit"));
    return (0);
}