/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:02:47 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 11:27:53 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap( void ): _name(""), _hit_point(0), _energy_point(0), _attack_damage(0){
	std::cout << ORG "ClapTrap default construcor is clalled!" RESET << std::endl;
}
ClapTrap::ClapTrap(std::string const name): _name(name), _hit_point(10), _energy_point(10), _attack_damage(0) {
	std::cout << ORG "ClapTrap name constructor is called!" RESET << std::endl;
}
ClapTrap::ClapTrap(ClapTrap const & other) {
	std::cout << ORG "ClapTrap copy constructor is called!" RESET << std::endl;
	*this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other) {
	std::cout << ORG "ClapTrap copy assignment operator is called!" RESET << std::endl;
	if (this != &other){
		_name = other._name;
		_hit_point = other._hit_point;
		_energy_point = other._energy_point;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap( void ) {
	std::cout << ORG "ClapTrap " GREEN << _name << ORG " destructor is called!" RESET << std::endl;
}

void	ClapTrap::attack(std::string const & target) {
	if(_energy_point && _hit_point){
		std::cout << ORG "ClapTrap " GREEN << _name << ORG " attacks: " << RED << target << ORG " causing " RED << _attack_damage << ORG " points of damage." RESET << std::endl;
		_energy_point--;
	}
	if (_hit_point == 0) 
		std::cout << GREEN << _name << ORG " is already dead!!!" << RESET << std::endl;
	if (_energy_point == 0)
		std::cout << GREEN << _name << ORG " doesn't have enough enegery to attack!" << RESET << std::endl;

}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_point == 0)
		std::cout << GREEN << _name << ORG " is already dead!" RESET << std::endl;
	else if (amount < _hit_point){
		std::cout << GREEN << _name << ORG " is damaged and " << RED << amount << ORG " health point is lost!" RESET << std::endl;
		_hit_point -= amount;
		return ;
	}
	else {
		std::cout << GREEN << _name << ORG " is damaged " << RED << amount << ORG " point that was more than its health point, so is just dead!" RESET << std::endl;
		_hit_point = 0;
	}
	return ;
}

void 	ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_point < amount){
		std::cout << GREEN << _name << ORG " is out of energy and could not reapir itself!" RESET << std::endl;
		return ;
	}
	std::cout << GREEN << _name << ORG " is repairing itself and lost " RESET << RED << amount << ORG " points!" RESET << std::endl;
	_energy_point--;
	_hit_point += amount;
	return ;
}

void	ClapTrap::report( void ) const {
	std::cout << GREEN << _name <<  ORG" has " RED <<  _hit_point << ORG " Health point, " <<
	RED << _energy_point << ORG " Energy point, and " RED << _attack_damage << ORG " Attack damage." << RESET << std::endl;
	return ;
}