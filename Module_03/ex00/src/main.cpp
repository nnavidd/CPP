/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 23:49:11 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main (int ac, char **av)
{
	if (ac == 3)
	{
		ClapTrap attacker(av[1]);
		attacker.attack(av[2]);
		attacker.report();
		return (0);
	}
	{
		ClapTrap instance1(ClapTrap("fish"));
		ClapTrap instance2(instance1);
		ClapTrap instance3 = instance2;
		ClapTrap instance4;

		instance4 = instance3;
		instance4.report();
		instance4.attack("reptile");
		instance4.report();
		instance4.takeDamage(100);
		instance4.report();
		instance4.takeDamage(100);
		instance4.report();
	}
	std::cout << std::endl;
	{		
			ClapTrap *ptr = new ClapTrap("birds");

		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->takeDamage(5);
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->beRepaired(1);
		ptr->report();
		ptr->takeDamage(5);
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->attack("reptile");
		ptr->report();
		ptr->takeDamage(5);
		ptr->report();
		ptr->takeDamage(5);
		ptr->report();
		delete ptr;
	}
	return (0);
}