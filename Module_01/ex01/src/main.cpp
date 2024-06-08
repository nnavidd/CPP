/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:26:03 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/07 18:22:52 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main (int ac, char **av)
{
    // int N;

    // std::cout << "Enter the Desired No. Of Zambies: " << std::endl;
    // std::cin >> N;
    // if (ac == 2)
    // {
    //     Zombie *zambies = zombieHorde(N, av[1]);
    //     for (int i = 0; i < N; i++)
    //         zambies[i].Announce();
    //     delete [] zambies;
    // }
    // else
    {
        (void) ac;
        (void) av;
        Zombie *zambies = zombieHorde(3, "Foo");
        for (int i = 0; i < 3; i++)
            zambies[i].Announce();
        delete [] zambies;
    }

    return (0);
}