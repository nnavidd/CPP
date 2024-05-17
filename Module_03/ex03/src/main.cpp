/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/17 22:36:10 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	dia("navid");
	ClapTrap	clap("maria");
	ClapTrap	*ptr1;
	ClapTrap	*ptr2;

	ptr1 = &dia;
	ptr2 = &clap;

	ptr1->attack("Dio_type");
	ptr1->report();
	ptr2->attack("clap_type");
	ptr2->report();
	dia.whoAmI();
    return (0);
}