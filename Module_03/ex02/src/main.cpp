/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 12:20:09 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main( void )
{
	FragTrap	instance("xxx");
	FragTrap	instance1;

	instance1 = instance;

	FragTrap	instance2( instance1 );
	FragTrap	instance3 = instance2;

	std::cout << std::endl;
	std::cout << RED "acting on instance 3: " RESET << std::endl;
	instance3.report();
	instance3.attack("yyy");
	instance3.report();
	instance3.beRepaired(20);
	instance3.report();
	instance3.highFivesGuys();
	instance3.takeDamage(30);
	
	std::cout << std::endl;
	std::cout << RED "instance 3 state: " RESET << std::endl;
	instance3.report();
	std::cout << std::endl;
	std::cout << RED "instance 2 state: " RESET << std::endl;
	instance2.report();
	std::cout << std::endl;
	std::cout << RED "instance 1 state: " RESET << std::endl;
	instance1.report();
	std::cout << std::endl;
	std::cout << RED "instance 0 state: " RESET << std::endl;
	instance.report();
	std::cout << std::endl;
    return (0);
}