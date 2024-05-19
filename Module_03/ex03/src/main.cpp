/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/19 10:35:35 by nnabaeei         ###   ########.fr       */
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

	DiamondTrap	dia("navid");
	ClapTrap	*ptr1;

	ptr1 = &dia;
	ptr1->attack("Dio_type");
	std::cout << std::endl;
	ptr1->report();
	std::cout << std::endl;
	dia.whoAmI();

	std::cout << std::endl;
    return (0);
}