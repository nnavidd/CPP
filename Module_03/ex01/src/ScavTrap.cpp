/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:19:56 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 11:54:16 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap default constructor is called!" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap name constructor is called!" << std::endl;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & other): ClapTrap(other) {
	std::cout << "ScavTrap copy constructor is called!" << std::endl;
	// *this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other) {
	std::cout << "ScavTrap copy assignment is called!" << std::endl;
	if (this != & other) {
		_name = other._name;
		_hit_point = other._hit_point;
		_energy_point = other._energy_point;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " GREEN << _name << RESET " destructor is called!" << std::endl;
}

void	ScavTrap::attack(std::string const & target){
	if(_energy_point && _hit_point){
		std::cout << "ScravTrap " GREEN << _name << RESET " attacks: " << RED << target << RESET " causing " RED << _attack_damage << RESET " points of damage." << std::endl;
		_energy_point--;
	}
	if (_hit_point == 0) 
		std::cout << "ScravTrap " GREEN << _name << RESET " is already dead!!!" << std::endl;
	if (_energy_point == 0)
		std::cout << "ScravTrap " GREEN << _name << RESET " doesn't have enough enegery to attack!" << std::endl;

}


void ScavTrap::guardGate() {
	std::cout << "ScavTrap " GREEN << _name << RESET " now in Gatekeeper mode" << std::endl;
}