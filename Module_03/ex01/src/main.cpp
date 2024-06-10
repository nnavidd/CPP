/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:03:49 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/10 11:46:40 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main( void )
{
    ScavTrap instance( "Ash" );
    ScavTrap instance2( instance );

    instance.report();
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