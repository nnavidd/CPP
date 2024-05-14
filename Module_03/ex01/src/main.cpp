/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/05/14 23:21:29 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main( void )
{
    ScavTrap instance( "Ash" );
    ScavTrap instance2( instance );

    instance2.report();
    instance2.report();
	instance2.attack( "the air" );
    instance2.report();
    instance2.takeDamage( 10 );
    instance2.report();
    instance2.beRepaired( 10 );
    instance2.report();
    instance2.guardGate();

    return (0);
}