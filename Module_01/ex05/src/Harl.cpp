/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:41 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/08 16:22:51 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug( void ) {
	std::cout << GREEN << "DEBUG:" ORG " I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" RESET << std::endl;
}
void Harl::info( void ) {
	std::cout << GREEN "INFO:" ORG " I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" RESET << std::endl;
}
void Harl::warning( void ) {
	std::cout << GREEN "WARNING:" ORG " I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." RESET << std::endl;
}
void Harl::error( void ) {
	std::cout << GREEN "ERROR:" ORG " This is unacceptable! I want to speak to the manager now." RESET << std::endl;
}


void	Harl::complain(std::string level)
{
	void (Harl::*LevelFunc[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	HarlLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			count;

	for (count = 0; count < 4 && HarlLevel[count] != level; ++count);
	if (count < 4)
		(this->*LevelFunc[count])();
	else {
		if (!level.compare("exit"))
			return ;
		std::cout << RED "Unknown Level!!!" RESET << std::endl;
	}
}
