/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:41 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/02 12:00:44 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"

Harl::Harl(){
	_HarlAction["DEBUG"] = &Harl::debug;
	_HarlAction["INFO"] = &Harl::info;
	_HarlAction["WARNING"] = &Harl::warning;
	_HarlAction["ERROR"] = &Harl::error;
}

Harl::~Harl(){}

void Harl::debug( void ) { 
	std::cout << BLUE << "[ DEBUG ]" << std::endl;
	std::cout << GREEN "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do!" RESET << std::endl;
	}

void Harl::info( void ) {
	std::cout << BLUE "[ INFO ]" << std::endl;
	std::cout << GREEN "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" RESET << std::endl;
	}

void Harl::warning( void ) {
	std::cout << BLUE "[ WARNING ]" << std::endl;
	std::cout << GREEN "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." RESET << std::endl;
	}

void Harl::error( void ) {
	std::cout << BLUE "[ ERROR ]" << std::endl;
	std::cout << GREEN "This is unacceptable! I want to speak to the manager now." RESET << std::endl;
	}

/*I defined the two different functions with the same usability in two different consepts:
 'LevelFunc' as: a pointer to the member functions inside the complain function, and
 'HarlAction' as: a assotiative container as a std::map member variable inside the Harl class. */
  
void	Harl::complian(std::string level)
{
	void (Harl::*LevelFunc[])() = {&Harl::debug, &Harl::info, &Harl::error, &Harl::warning};
	std::string	HarlLevel[] = {"DEBUG", "INFO", "ERROR", "WARNING", "exit"};
	int			count;

	for (count = 0; HarlLevel[count] != level && count < 5; count++);
	switch (count)
	{
		case 0:
			(this->*LevelFunc[0])();
			break;
		case 1:
			(this->*LevelFunc[1])();
			break;
		case 2:
			(this->*LevelFunc[2])();
			break;
		case 3:
			(this->*LevelFunc[3])();
			break;
		case 4:
			std::cout << ORG "Project is finished!" RESET << std::endl;
			break;
		default:
			std::cout <<RED "[ Probably complaining about insignificant problems ]" RESET<< std::endl;
			break;
	}
}
void	Harl::HarlFilter(std::string level)
{
	std::string	HarlLevel[] = {"DEBUG", "INFO", "ERROR", "WARNING", "exit"};
	int			count;

	for (count = 0; HarlLevel[count] != level && count < 5; count++);
	switch (count)
	{
		case 0:
			(this->*_HarlAction["DEBUG"])();
			break;
		case 1:
			(this->*_HarlAction["INFO"])();
			break;
		case 2:
			(this->*_HarlAction["ERROR"])();
			break;
		case 3:
			(this->*_HarlAction["WARNING"])();
			break;
		case 4:
			std::cout << ORG "Project is finished!" RESET << std::endl;
			break;
		default:
			std::cout <<RED "[ Probably complaining about insignificant problems ]" RESET<< std::endl;
			break;
	}
}

