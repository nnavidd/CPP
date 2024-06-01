/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:35:30 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/01 09:42:00 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/AMateria.hpp"

Character::Character( void ) : _name(""){
 	std::cout << MAGENTA "Character" RESET " default constructor is called" << std::endl;
	for(int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const name) : _name(name){
 	std::cout << MAGENTA "Character" RESET " default constructor is called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name) {
 	std::cout << MAGENTA "Character" RESET " copy constructor is called" << std::endl;
	for (int i = 0; i < 4; ++i)
        _inventory[i] = NULL;
	copyInventory(other);
}

Character& Character::operator=(const Character& other) {
 	std::cout << MAGENTA "Character" RESET " copy assignment is called" << std::endl;
	if (this != &other) {
		_name = other._name;
		clearInventory();
		copyInventory(other);
	}
	return *this;
}

Character::~Character() {
 	std::cout << MAGENTA "Character" RESET " destructor is called" << std::endl;
	clearInventory();
}

const std::string& Character::getName() const {
 	std::cout << MAGENTA "Character" RESET " getName is called" << std::endl;
	return _name;
}

void Character::equip(AMateria* m) {
 	std::cout << MAGENTA "Character" RESET " equip is called" << std::endl;
	if (!m) 
		return;
	for (int i = 0; i < 4; ++i) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx) {
 	std::cout << MAGENTA "Character" RESET " unequip is called" << std::endl;
	if (idx >= 0 && idx < 4) {
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
 	std::cout << MAGENTA "Character" RESET " use is called" << std::endl;
	if (idx >= 0 && idx < 4 && _inventory[idx]) {
		_inventory[idx]->use(target);
	}
}

void Character::clearInventory() {
 	std::cout << MAGENTA "Character" RESET " clearInventory is called" << std::endl;
	for (int i = 0; i < 4; ++i) {
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

void Character::copyInventory(const Character& other) {
 	std::cout << MAGENTA "Character" RESET " copyInventory is called" << std::endl;
	for (int i = 0; i < 4; ++i) {
		if (other._inventory[i]) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
	}
}