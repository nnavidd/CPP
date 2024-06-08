/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:09:25 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 18:36:37 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string type): _Type(type){};
Weapon::~Weapon(){};
void Weapon::setType(std::string type){
	this->_Type = type;
}
const std::string & Weapon::getType( void ) const {
	return (_Type);
}
