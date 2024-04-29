/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:09:25 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/29 00:30:51 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type): _Type(type){};
Weapon::~Weapon(){};
void Weapon::setType(std::string type){
	this->_Type = type;
}
const std::string& Weapon::getType(void) const {
	return (_Type);
}
