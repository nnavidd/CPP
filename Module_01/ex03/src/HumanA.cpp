/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:36:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 18:49:39 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon & type): _Name(name), _Weapon(type){}
HumanA::~HumanA(){}

void	HumanA::attack( void ) const {
	if (_Weapon.getType() != "")
		std::cout << BLUE << _Name << RESET " attacks with their " CYAN << _Weapon.getType() << RESET << std::endl;
	else
		std::cout << BLUE << _Name << RESET " doesn't have a weapon to attack." << std::endl;
}