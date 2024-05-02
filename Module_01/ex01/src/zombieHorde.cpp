/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:25:38 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/04/26 18:30:43 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie      *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}
