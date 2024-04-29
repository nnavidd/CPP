/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:36:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/29 00:38:58 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type): _Name(name), _Weapon(type){}
HumanA::~HumanA(){}

void	HumanA::attack( void ) const {
	if (_Weapon.getType() != "")
		std::cout << _Name << " attacks with their " << _Weapon.getType() << std::endl;
	else
		std::cout << _Name << " doesn't have a weapon to attack." << std::endl;
}