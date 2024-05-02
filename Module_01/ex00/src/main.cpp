/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:29:45 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/27 09:29:47 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main (int ac, char **av)
{
    if (ac == 3)
    {
        Zombie  *New = newZombie(av[1]);
        New->Announce();
        randomChump(av[2]);
        delete New;
    }
    else
    {
        Zombie  *New = newZombie("Foo");
        New->Announce();
        randomChump("Joo");
        delete New;
    }
    return (0);
}