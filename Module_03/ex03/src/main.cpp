/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 13:11:51 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main( void )
{
	{
		DiamondTrap	instance("xxx");
		std::cout << std::endl;
	
		DiamondTrap	instance1;
		std::cout << std::endl;
	
		instance1 = instance;
		std::cout << std::endl;
	
		DiamondTrap	instance2(instance1);
		std::cout << std::endl;
	
		instance.whoAmI();
		instance1.whoAmI();
		instance2.whoAmI();
		std::cout << std::endl;
	}
	
	std::cout << std::endl;

	DiamondTrap	dia("zzz");
		std::cout << std::endl;
	ClapTrap	*ptr1;
		std::cout << std::endl;

	ptr1 = &dia;
		std::cout << std::endl;
	ptr1->attack("Dio_type");
	std::cout << std::endl;
	ptr1->report();
	std::cout << std::endl;
	dia.whoAmI();

	std::cout << std::endl;
    return (0);
}