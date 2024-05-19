/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 00:06:38 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/19 10:27:21 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ):ClapTrap(), ScavTrap(), FragTrap(), _name(""){
	std::cout << CYAN "DiamondTrap" RESET " default constructor is called!" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name): ClapTrap(name + "_Clap"), ScavTrap(), FragTrap(), _name(name){
	std::cout << CYAN "DiamondTrap" RESET " name constructor is called to create: " << GREEN << _name << RESET << std::endl;	
	_hit_point = FragTrap::_hit_point;
	_energy_point = ScavTrap::_energy_point;
	_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & other):ClapTrap(other), ScavTrap(other), FragTrap(other){
	std::cout << CYAN "DiamondTrap" RESET " copy constructor is called!" << std::endl;
	*this = other;	
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other){
	std::cout << CYAN "DiamondTrap" RESET " assignment operator is called!" << std::endl;	
	_name = other._name;
	_hit_point = other._hit_point;
	_energy_point = other._energy_point;
	_attack_damage = other._attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap( void ){
	std::cout << CYAN "DiamondTrap " GREEN <<_name << RESET " destructor is called!" << std::endl;	
}

void	DiamondTrap::attack(std::string const & target){
	if(_energy_point && _hit_point){
		std::cout << CYAN "DiamondTrap " GREEN << _name << RESET " attacks: " << RED << target << RESET " causing " RED << _attack_damage << RESET " points of damage." << std::endl;
		_energy_point--;
	}
	else if (_hit_point == 0) 
		std::cout << CYAN "DiamondTrap <" GREEN << _name << RESET "> is already dead!!!" << std::endl;
	else if (_energy_point == 0)
		std::cout << CYAN "DiamondTrap " GREEN << _name << RESET " doesn't have enough enegery to attack!" << std::endl;

}

void	DiamondTrap::whoAmI( void ) {
	std::cout << " I am a " CYAN "DiamondTrap named " GREEN << _name << RESET " has " RED <<  _hit_point << RESET " Health point, " <<
	RED << _energy_point << RESET " Energy point, and " RED << _attack_damage << RESET " Attack damage." << RESET << std::endl;
	return ;
}
