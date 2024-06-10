/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:55:46 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 13:06:01 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

FragTrap::FragTrap( void ): ClapTrap(){
	std::cout <<  BLUE "FragTrap" RESET " default constructor is called!" << std::endl;
}

FragTrap::FragTrap( std::string name): ClapTrap(name){
	std::cout <<BLUE "FragTrap" RESET " name constructor is called!" << std::endl;
	_hit_point = 100;
	_energy_point = 50;
	_attack_damage = 20;
}

FragTrap::FragTrap(FragTrap const & other): ClapTrap(other){
	std::cout << BLUE "FragTrap" RESET " copy constructor is called!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & other){
	std::cout << BLUE "FragTrap" RESET " assignment operator is called!" << std::endl;
	if (this != &other){
		_name = other._name;
		_hit_point = other._hit_point;
		_energy_point = other._energy_point;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap( void ){
	std::cout << BLUE "FragTrap " GREEN << _name << RESET " destructor is called!" << std::endl;
}

void	FragTrap::highFivesGuys( void ){
	std::cout <<  BLUE "FragTrap" RESET " is displaying ✋✋✋ !!!" << std::endl;
}