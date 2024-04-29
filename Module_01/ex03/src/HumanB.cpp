/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 10:36:02 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/29 10:03:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name): _Name(name), _Weapon(NULL) {}
HumanB::~HumanB(){}
void	HumanB::setWeapon(Weapon& weapon){
	_Weapon = &weapon;
}
void    HumanB::attack( void ) const {
    if (this->_Weapon && this->_Weapon->getType() != "")
        std::cout << _Name << " attacks with their " << this->_Weapon->getType() << std::endl;
    else
        std::cout << _Name << " doesn't have a weapon to attack." << std::endl;
}
