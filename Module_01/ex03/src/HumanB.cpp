/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:36:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 18:47:59 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name): _Name(name), _Weapon(NULL) {}
HumanB::~HumanB(){}
void	HumanB::setWeapon(Weapon & weapon){
	_Weapon = & weapon;
}
void    HumanB::attack( void ) const {
    if (this->_Weapon && this->_Weapon->getType() != "")
        std::cout << GREEN << _Name << RESET " attacks with their " MAGENTA << this->_Weapon->getType() << RESET << std::endl;
    else
        std::cout << GREEN << _Name << RESET " doesn't have a weapon to attack." << std::endl;
}
