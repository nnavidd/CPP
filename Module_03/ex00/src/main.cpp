/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 18:03:26 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main (int ac, char **av)
{
	// if(ac == 1){
	// 	ClapTrap attacker("Navid");
	// 	attacker.attack("xxx");
	// 	attacker.report();
	// }
	if (ac == 3)
	{
		ClapTrap attacker(av[1]);
		attacker.attack(av[2]);
		attacker.report();
		return (0);
	}
	{
		ClapTrap instance1(ClapTrap("Moth"));
		ClapTrap instance2(instance1);
		ClapTrap instance3 = instance2;
		ClapTrap instance4;

		instance4 = instance3;
		instance4.report();
		instance4.attack("Sauron");
		instance4.report();
		instance4.takeDamage(100);
		instance4.report();
		instance4.takeDamage(100);
		instance4.report();
	}
	{		
			ClapTrap *butterfly = new ClapTrap("Butterfly");

		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->takeDamage(5);
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->beRepaired(1);
		butterfly->report();
		butterfly->takeDamage(5);
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->attack("Sauron");
		butterfly->report();
		butterfly->takeDamage(5);
		butterfly->report();
		butterfly->takeDamage(5);
		butterfly->report();
		delete butterfly;
	}
	return (0);
}