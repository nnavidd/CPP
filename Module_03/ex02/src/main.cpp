/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/15 11:47:18 by nnabaeei         ###   ########.fr       */
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

	instance3.report();
	instance3.attack("yyy");
	instance3.report();
	instance3.beRepaired(20);
	instance3.report();
	instance3.highFivesGuys();
	instance3.takeDamage(30);

	std::cout << "instance 3 state: " << std::endl;
	instance3.report();
	std::cout << "instance 2 state: " << std::endl;
	instance2.report();
	std::cout << "instance 1 state: " << std::endl;
	instance1.report();
	std::cout << "instance 0 state: " << std::endl;
	instance.report();
    return (0);
}