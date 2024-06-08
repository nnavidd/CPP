/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:41 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/08 11:06:09 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(){
	_HarlAction["DEBUG"] = &Harl::debug;
	_HarlAction["INFO"] = &Harl::info;
	_HarlAction["WARNING"] = &Harl::warning;
	_HarlAction["ERROR"] = &Harl::error;
}

Harl::~Harl(){
	
}

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


void	Harl::complian(std::string level)
{
	std::map<std::string, Level>::iterator iter = _HarlAction.find(level);
	if (iter != _HarlAction.end())
		(this->*_HarlAction[level])();
	else if (!level.compare("exit"))
		std::cout << ORG "Project is exited" RESET<< std::endl;
	else
		std::cout <<RED "Unknown Level!!!" RESET<< std::endl;
}
